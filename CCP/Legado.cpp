/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Omegaup.com
Problem: El legado más grande
Section: first CCP (Copa Centroamericana de Programacion)
link to the problem 
https://omegaup.com/arena/ccp-2020-public/#problems (link to the contest)
https://omegaup.com/arena/problem/1er-ccp-abues/#problems (link to the problem)
link to the video where I solve it:
https://youtu.be/-_mU3Sofz6M
*/
#include <bits/stdc++.h>
#define inf 1000000000
#define tam 100000

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <vi> graph;

bool comp(ll a, ll b) {
	return a > b;
}

int n, cont;
graph grafo;
vi degree, d, hijos, nietos;
map <string, int> kika;
map <int, string> rkika;

void dag() {
    queue <int> cola;
    for (int i = 1; i <= cont; i++) {
        if (!degree[i]) {cola.push(i); d[i] = 0;}
    }
    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        for (int v : grafo[u]) {
            if (d[v] == inf) {
                d[v] = d[u] + 1;
            }
            degree[v]--;
            nietos[v] += hijos[u];
            if (!degree[v]) cola.push(v);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    cin >> n;
    string s, t;
    vii query;
    query.reserve(n);
    cont = 1;
    int in1, in2;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        if (!kika[s]) {kika[s] = cont; rkika[cont] = s; cont++;}
        if (!kika[t]) {kika[t] = cont; rkika[cont] = t; cont++;}
        in1 = kika[s];
        in2 = kika[t];
        query.push_back({in1, in2});
    }
    grafo.assign(cont + 5, vi() );
    degree.assign(cont + 5, 0);
    d.assign(cont + 5, inf);
    hijos.assign(cont + 5, 0);
    nietos.assign(cont + 5, 0);
    for (int i = 0; i < n; i++) {
        in1 = query[i].first;
        in2 = query[i].second;
        grafo[in1].push_back(in2);
        hijos[in2]++;
        degree[in2]++;
    }
    dag();
    vi ans;
    ans.reserve(cont);
    int mayor = 0;
    for (int i = 1; i < cont; i++) {
        if (nietos[i] > mayor) {
            mayor = nietos[i];
            ans.resize(0);
            ans.push_back(i);
        } else if (nietos[i] == mayor) ans.push_back(i);
    }
    vector <string> nombre;
    nombre.reserve(ans.size());
    for (int x : ans) {
        nombre.push_back(rkika[x]);
    }
    sort(nombre.begin(), nombre.end());
    for (string x : nombre) {
        cout << x << " ";
    }
    cout << "\n";
	return 0;
}
