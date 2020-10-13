/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Codeforces.com
Problem: Numbers on tree
section: Codeforces round 612 (Div 1)
link to the problem 
https://codeforces.com/contest/1286/problem/B
link to the video where I solve it:
https://youtu.be/DxDB_-B5x9E (video in Spanish)
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
#define inf 1000000000

using namespace std;

int n;
graph grafo;
vi c;
bool band;

void insertar(int pos, int val, vi &temp) {
	vi copia;
	copia.reserve(n);
	for (int i = 0; i < pos; i++) copia.push_back(temp[i]);
	copia.push_back(val);
	for (int i = pos; i < temp.size(); i++) copia.push_back(temp[i]);
	temp = copia;
}

vi dfs1 (int u) {
	vi lista, temp;
	lista.reserve(n);
	temp.reserve(n);
	for (int v : grafo[u]) {
		temp = dfs1(v);
		for (int i : temp) lista.push_back(i);
	}
	if (c[u] <= lista.size()) {
		insertar(c[u], u, lista);
	} else {
		band = false;
	}
	return lista;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    int in1, in2, r;
 	c.assign(n + 1, 0);
    grafo.assign(n + 1, vi());
    band = true;
    REP(1, n + 1) {
    	cin >> in1 >> in2;
    	if (!in1) r = i;
    	grafo[in1].push_back(i);
    	c[i] = in2;
    }
    vi lista = dfs1(r);
    vi ans(n + 1, 0);
    int cont = 1;
	if (band) {
		cout << "YES\n";
		for (int i : lista) {
			ans[i] = cont++;
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << "\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}
