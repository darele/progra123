/*
By progra123 (https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ)
CSES.fi
Problem: Number Spiral
section: Introductory problems
link to the problem 
https://cses.fi/problemset/task/1071
link to the video where I solve it: 
https://youtu.be/9Uxz9KYXn8c (Video in Spanish)
*/

#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        ll m = max(y, x);
        ll i, j;
        ll temp = m * m;
        if (m % 2 == 0) {
            i = m, j = 1;
            temp += (j - x);
            temp += (y - i);
        } else {
            i = 1, j = m;
            temp += (i - y);
            temp += (x - j);
        }
        cout << temp << "\n";
    }
	return 0;
}
