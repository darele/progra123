/*
By progra123 (https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ)
link to the video where I explain this concept: 
https://youtu.be/wwxkcyVUVzc (spanish)
https://youtu.be/Mk3YXKJp-H0 (english)
*/
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
