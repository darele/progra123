/*
By progra123 (https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ)
CSES.fi
Problem: Apple Division
section: Introductory problems
link to the problem (https://cses.fi/problemset/task/1623/)
link to the video where I solve it: https://youtu.be/qf-0Pghhd8U
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 10000000000ll

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int n;
	cin >> n;
	ll arr[n];
	ll suma = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		suma += arr[i];
	}
	ll cur;
	ll ans = inf;
	for (int i = 0; i < (1 << (n + 1)); ++i)
	{
		cur = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j)) cur += arr[j];
		}
		ans = min(ans, abs((suma - cur) - cur));
	}
	cout << ans << "\n";
	return 0;
}
