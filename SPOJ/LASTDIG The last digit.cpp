#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans *= a;
                ans %= 10;
            }
            a *= a;
            a %= 10;
            b >>= 1ll;
        }
        cout << ans << "\n";
    }
	return 0;
}
