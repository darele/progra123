/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Omegaup.com
Problem: Don-Porfirio
section: CIIC-2016 problem 3
link to the problem 
https://omegaup.com/arena/problem/don-porfirio/#problems (link to the problem)
https://omegaup.com/arena/CIIC-2016/ (link to the contest)
link to the video where I solve it:
*/
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define ii pair <int, int>
#define iii pair <ll, ii>

using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int n;
ll suma;

class uf {
public:
	vi p;
	vl s;
	uf() {
		p.assign(n + 5, 0);
		s.assign(n + 5, 1);
		for (int i = 0; i < n + 5; i++) p[i] = i;
	}
	int findset(int u) {return u == p[u] ? u : p[u] = findset(p[u]);}
	void merge(int u, int v, ll b) {
		int x, y;
		x = findset(u);
		y = findset(v);
		suma += ((((s[x] * s[y]) % mod) * b) % mod);
		suma %= mod;
		if (s[x] > s[y]) {
			p[y] = x;
			s[x] += s[y];
		} else {
			p[x] = y;
			s[y] += s[x];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	int in1, in2;
	ll in3;
	iii arr[n - 1];
	for (int i = 0; i < n - 1; i++) {
		cin >> in1 >> in2 >> in3;
		arr[i] = {in3, {in1, in2}};
	}
	sort(arr, arr + n - 1);
	suma = 0;
	uf kika;
	for (int i = 0; i < n - 1; i++) {
		in3 = arr[i].first;
		in1 = arr[i].second.first;
		in2 = arr[i].second.second;
		kika.merge(in1, in2, in3);
	}
	cout << suma << "\n";
	return 0;
}
