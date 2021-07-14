/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Codeforces.com
Problem: Dividing Candy
section: 2020-2021 ACM-ICPC Latin American Regional Programming Contest
link to the problem 
https://codeforces.com/gym/103185/problem/D
link to the video where I solve it:
https://youtu.be/VMXCFrFDWsc (video in spanish)
*/

#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define tam 2e05 + 5

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "N\n";
        return 0;
    }
    if (n == 2) {
        cout << "Y\n";
        return 0;
    }
    vi rep(tam, 0);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        rep[x]++;
        while (rep[x] == 2) {
            rep[x] = 0;
            rep[x + 1]++;
            x++;
        }
    }
    int cont = 0;
    for (int i : rep) {
        if (i > 0) cont++;
    }
    if (cont < 3) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    return 0;
}

