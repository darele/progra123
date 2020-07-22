/*
Link to the problem:
https://codeforces.com/problemset/problem/1067/B
*/
#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <vi>

using namespace std;

int n, k;
graph grafo;
vi p;
vi temp;
vi degree;
bool band;
int h, c;
int d, mayor;

void dfs(int u) {
	if (h < k) {
		if (degree[u] < 3) band = false;
	}
	if (h == k) {
		if (degree[u]) band = false;
	}
	h++;
	for (int v : grafo[u]) {
		if (v != p[u]) {
			p[v] = u;
			degree[v]--;
			dfs(v);
		}
	}
	h--;
}

void centro(int u) {
	temp.push_back(u);
	d++;
	if (d > mayor) {
		mayor = d;
		c = temp[mayor / 2];
	}
	for (int v : grafo[u]) {
		if (v != p[u]) {
			p[v] = u;
			centro(v);
		}
	}
	d--;
	temp.pop_back();
}

void centro() {
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 1) {
			temp.push_back(i);
			int v = grafo[i][0];
			d = 1;
			mayor = 0;
			centro(v);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> k;
	grafo.assign(n + 5, vi ());
	degree.assign(n + 5, 0);
	p.assign(n + 5, 0);
	int in1, in2;
	for (int i = 1; i < n; i++) {
		cin >> in1 >> in2;
		grafo[in1].push_back(in2);
		grafo[in2].push_back(in1);
		degree[in1]++;
		degree[in2]++;
	}
	centro();
	band = true;
	p.assign(n + 5, 0);
	dfs(c);
	if (band) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
