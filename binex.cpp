#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll binex(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ans;
}

int main() {

	ll a, b;
	cin >> a >> b;
	cout << binex(a, b) << "\n";
	return 0;
}