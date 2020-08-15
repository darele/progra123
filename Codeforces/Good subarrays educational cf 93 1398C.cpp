/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Codeforces.com
Problem: Good Subarrays
section: Educational Cf round 93 problem C
link to the problem 
https://codeforces.com/contest/1398/problem/C
link to the video where I solve it:
https://youtu.be/MoEuYe6AjDY (video in spanish)
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll suma = 0;
        ll ans = 0;
        map <ll, ll> kika;
        kika[0] = 1;
        for (int i = 0; i < n; i++) {
            suma += (ll)s[i] - '0' - 1;
            ans += kika[suma];
            kika[suma]++;
        }
        cout << ans << "\n";
    }
	return 0;
}
