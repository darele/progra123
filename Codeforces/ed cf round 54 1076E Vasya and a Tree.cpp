#include <bits/stdc++.h>
#define ll long long
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define tam 300005

using namespace std;

int n;
graph grafo;
map <int, ll> arr[tam];
int h;
ll sum;
ll seg[tam];
ll ans[tam];
int p[tam];

void dfs(int u) {
    for (auto x : arr[u]) {
        seg[h] += x.second;
        if (h + x.first <= n) seg[h + x.first + 1] -= x.second;
    }
    sum += seg[h];
    ans[u] = sum;
    h++;
    for (int v : grafo[u]) {
        if (v != p[u]) {
            p[v] = u;
            dfs(v);
        }
    }
    h--;
    sum -= seg[h];
    for (auto x : arr[u]) {
        seg[h] -= x.second;
        if (h + x.first <= n) seg[h + x.first + 1] += x.second;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    grafo.assign(n + 5, vi());
    ll in1, in2, in3;
    for (int i = 1; i < n; i++) {
        cin >> in1 >> in2;
        grafo[in1].push_back(in2);
        grafo[in2].push_back(in1);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> in1 >> in2 >> in3;
        arr[in1][in2] += in3;
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
	return 0;
}
