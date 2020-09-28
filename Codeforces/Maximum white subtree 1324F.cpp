/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Codeforces.com
Problem: Maximum White Subtree
section: Round 623 Div 3 problem F
link to the problem 
https://codeforces.com/contest/1324/problem/F
link to the video where I solve it:
https://youtu.be/E9KhBUWQC4A (video in spanish)
*/

#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define graph vector <vi>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

#define tam 200005

using namespace std;

int n;
graph grafo;
vi r;
vi p;
vi c;
vi up;

void dfs(int u) {
	r[u] = c[u];
	for (int v : grafo[u]) {
		if (v == p[u]) continue;
		p[v] = u;
		dfs(v);
		r[u] += max(r[v], 0);
	}
}

void dfs2(int u) {
	for (int v : grafo[u]) {
		if (v == p[u]) continue;
		up[v] = max(r[u] - max(r[v], 0) + up[u], 0);
		dfs2(v);
	}
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    int in1, in2;
    grafo.assign(n + 1, vi());
    r.assign(n + 1, 0);
    p.assign(n + 1, 0);
    c.assign(n + 1, 0);
    up.assign(n + 1, 0);
    REP(1, n + 1) {
    	cin >> c[i];
    	if (!c[i]) c[i] = -1;
    }
    REP(1, n) {
    	cin >> in1 >> in2;
    	grafo[in1].push_back(in2);
    	grafo[in2].push_back(in1);
    }
    dfs(1);
    dfs2(1);
    REP(1, n + 1) {
    	cout << r[i] + up[i] << " ";
    }
    cout << "\n";
    return 0;
}
