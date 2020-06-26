/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
spoj.com
Problem: Just add it
link to the problem 
https://www.spoj.com/problems/ZSUM/
link to the video where I solve it:
https://youtu.be/wwxkcyVUVzc
*/
#include <bits/stdc++.h>
#define ll long long
#define mod 10000007

using namespace std;

ll binex(ll a, ll b) {
	ll ans = 1;
	a %= mod;
	while (b) {
		if (b & 1) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ans;
}

int main() {

	ll n, k;
	while (1) {
		ll n, k;
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		ll ans = (2 * binex(n - 1, k)) % mod;
		ans += (2 * binex(n - 1, n - 1)) % mod;
		ans %= mod;
		ans += binex(n, n);
		ans %= mod;
		ans += binex(n, k);
		ans %= mod;
		cout << ans << "\n";
	}

	return 0;
}
