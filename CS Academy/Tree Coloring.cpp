/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
CSAcademy
Problem: Tree Coloring
link to the problem 
https://csacademy.com/contest/archive/task/tree-coloring/statement/
link to the video where I solve it:
https://youtu.be/wu521P50PWw
*/

#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define mod 1000000007

using namespace std;

ll n, k;
graph grafo;
vi p;

ll dfs(int u, ll val) {
    ll cans = val;
    int cont = 1;
    if (p[u]) cont++;
    for (int v : grafo[u]) {
        if (v == p[u]) continue;
        p[v] = u;
        cans *= dfs(v, k - cont);
        cont++;
        cans %= mod;
    }
    return cans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    grafo.assign(n + 5, vi());
    p.assign(n + 5, 0);
    int in1, in2;
    for (int i = 1; i < n; i++) {
        cin >> in1 >> in2;
        grafo[in1].push_back(in2);
        grafo[in2].push_back(in1);
    }
    cout << dfs(1, k) << "\n";
	return 0;
}
