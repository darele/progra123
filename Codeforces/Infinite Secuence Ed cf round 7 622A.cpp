/*
https://codeforces.com/contest/622/problem/A
*/

/*
//busqueda binaria
#include <bits/stdc++.h>
#define ll uint64_t
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll ini, fin, mid;
    ini = 1, fin = 10000000000, mid = (ini + fin) / 2;
    ll temp;
    while (fin > ini) {
        temp = (mid * (mid + 1)) / 2;
        if (temp >= n) fin = mid - 1;
        else ini = mid + 1;
        mid = (ini + fin) / 2;
    }
    temp = ((mid + 2) * (mid + 1)) / 2;
    if (temp < n) {
        n -= temp;
        cout << n << "\n";
    } else {
        temp = (mid * (mid + 1)) / 2;
        if (temp < n) {
            n -= temp;
            cout << n << "\n";
        } else {
            mid--;
            temp = (mid * (mid + 1)) / 2;
            n -= temp;
            cout << n << "\n";
        }
    }
	return 0;
}
*/

/*
//busqueda lineal
#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define graph vector <vector <int> >
#define inf 1000000000

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long suma = 1;
    ll ac = 2;
    while (suma < n) {
        suma += ac;
        ac++;
    }
    //cout << ac << endl;
    ac--;
    suma -= ac;
    n -= suma;
    cout << n << "\n";
    return 0;
}
*/
