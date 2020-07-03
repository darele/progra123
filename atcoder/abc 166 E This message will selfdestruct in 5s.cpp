/*
By progra123 (https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ)
platform: atcoder.jp
Problem: This message will selfdestruct in 5s
contest: atcoder beginner contest 166
link to the problem (https://atcoder.jp/contests/abc166/tasks/abc166_e)
link to the video where I solve it
https://youtu.be/kDimkhUR1Io
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 10000000000ll

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	ll n;
	cin >> n;
	ll arr[n];
	map <ll, ll> count;
	for (int i  = 0; i < n; i++) {
	    cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
	    count[arr[0] + arr[i] - i]++;
	}
	ll ans = count[0];
	ll cur = 0;
	for (int i = 1; i < n - 1; i++) {
	    count[arr[0] + arr[i] - i]--;
	    cur = arr[0] - arr[i] - i;
	    ans += count[cur];
	}
	cout << ans << "\n";
	return 0;
}
