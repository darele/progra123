#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <vii> graph;

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int h, l;
    cin >> h >> l;
    int in;
    int arr[l];
    for (int i = 0; i < l; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + l);
    int suma = 0;
    h *= 60;
    int cont = 0;
    int pre[l + 1];
    pre[0] = 0;
    for (int i = 0; i < l; i++) {
        if (suma + arr[i] > h) break;
        cont++;
        suma += arr[i];
        pre[i + 1] = pre[i] + arr[i];
    }
    vi ans;
    ans.reserve(cont);
    int temp = 1;
    suma = 0;
    for (int i = l - 1; i >= 0; i--) {
        if (suma + arr[i] + pre[cont - temp] <= h) {suma += arr[i]; ans.push_back(arr[i]); temp++;}
    }
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
	return 0;
}
