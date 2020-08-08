/*
By Progra123
https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ
Video where I explain the theory behind this
https://youtu.be/c0KmINJL4Ag (Spanish)
*/
#include <bits/stdc++.h>
#define vi vector <int>
#define graph vector <vector <int> >
//ajustar inf segun sea necesario
#define inf 1000000000

using namespace std;

int n, m;
graph grafo;
bitset <10000> vis;
vi dist;

void dfs(int u) {
    //camino generado por dfs
    cout << u << "\n";
    vis[u] = 1;
    for (int v : grafo[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void bfs(int s) {
    queue <int> cola;
    dist.assign(n + 5, inf);
    cola.push(s);
    dist[s] = 0;
    while (!cola.empty()) {
        int u = cola.front();
        //camino generado por bfs
        cout << u << "\n";
        cola.pop();
        for (int v : grafo[u]) {
            if (dist[v] == inf) {
                dist[v] = dist[u] + 1;
                cola.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    //Grafo en forma de lista de adyacencia
    grafo.assign(n + 5, vi());
    int in1, in2;
    for (int i = 0; i < m; i++) {
        cin >> in1 >> in2;
        grafo[in1].push_back(in2);
        grafo[in2].push_back(in1);
    }
    bfs(1);
    dfs(1);
    return 0;
}
