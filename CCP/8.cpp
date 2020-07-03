#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define graph vector <vi>
#define inf 1000000000
#define iii pair <int, ii>

using namespace std;
 
bool comp(int a, int b) {
	return a > b;
}

int n;
vector <vector <int> > mat;
vector <vector <vector <bool> > > vis;
priority_queue <iii, vector <iii>, greater <iii> > cola;
int menor;

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};

void f(int i, int j, int t) {
	if (i == n - 1 && j == n - 1) {
		menor = min(menor, t);
		return;
	}
	if (vis[i][j][t % 10]) return;
	int nivel = ((t / 5) % 2 == 0 ? t % 5 : 5 - (t % 5));
	vis[i][j][t % 10] = 1;
	for (int k = 0; k < 4; k++) {
		int temp1, temp2;
		temp1 = i + x[k];
		temp2 = j + y[k];
		if (temp1 >= n || temp1 < 0 || temp2 >= n || temp2 < 0) continue;
		if ((t / 5) % 2 == 0) {
			if (nivel < mat[temp1][temp2]) {
				if (!vis[temp1][temp2][(t + 1) % 10]) cola.push({t + 1, {temp1, temp2}});
			}
			if (mat[i][j] == 5) {
				int extra = abs(5 - nivel);
				extra += (5 - mat[temp1][temp2]);
				if (!vis[temp1][temp2][(t + extra) % 10]) cola.push({t + extra, {temp1, temp2}});
			}
		} else {
			if (nivel <= mat[temp1][temp2] + 1) {
				if (!vis[temp1][temp2][(t + 1) % 10]) cola.push({t + 1, {temp1, temp2}});
			} else {
				int temp = t + nivel - mat[temp1][temp2];
				if (!vis[temp1][temp2][temp % 10]) cola.push({temp, {temp1, temp2}});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 	
	cin >> n;
	mat.resize(n);
	vis.resize(n);
	for (int i = 0; i < n; i++) {
		mat[i].resize(n);
		vis[i].resize(n);
		for (int j = 0; j < n; j++) {
			vis[i][j].assign(11, 0);
			cin >> mat[i][j];
		}
	}
	cola.push({0, {0, 0}});
	menor = inf;
	while (!cola.empty()) {
		iii u = cola.top();
		cola.pop();
		f(u.second.first, u.second.second, u.first);
	}
	if (menor != inf) cout << menor << "\n";
	else cout << "-1\n";
	return 0;
}
