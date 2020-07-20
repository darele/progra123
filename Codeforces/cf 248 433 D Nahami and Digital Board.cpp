/*https://codeforces.com/problemset/problem/433/D*/

#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, ll>
#define vi vector <int>
#define graph vector <vi>
#define tam 1005
using namespace std;

ll u[tam][tam];
ll d[tam][tam];
ll r[tam][tam];
ll l[tam][tam];
bool mat[tam][tam];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	ll in1, in2, in3;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= m; j++) {
	        if (!mat[i][j]) continue;
	        l[i][j] = l[i][j - 1] + 1;
	        u[i][j] = u[i - 1][j] + 1;
	    }
	}
	for (int i = n; i > 0; i--) {
	    for (int j = m; j > 0; j--) {
	        if (!mat[i][j]) continue;
	        d[i][j] = d[i + 1][j] + 1;
	        r[i][j] = r[i][j + 1] + 1;
	    }
	}
	for (int k = 0; k < q; k++) {
		cin >> in1 >> in2 >> in3;
		if (in1 == 1) {
			mat[in2][in3] = !mat[in2][in3];
			if (mat[in2][in3]) {
			    u[in2][in3] = u[in2 - 1][in3] + 1;
			    d[in2][in3] = d[in2 + 1][in3] + 1;
			    l[in2][in3] = l[in2][in3 - 1] + 1;
			    r[in2][in3] = r[in2][in3 + 1] + 1;
			} else {
			    u[in2][in3] = d[in2][in3] = l[in2][in3] = r[in2][in3] = 0;
			}
			for (int i = in2 - 1; mat[i][in3] && i > 0; i--) {
			    d[i][in3] = d[i + 1][in3] + mat[i][in3];
			}
			for (int i = in2 + 1; mat[i][in3] && i <= n; i++) {
			   u[i][in3] = u[i - 1][in3] + mat[i][in3];
			}
			for (int i = in3 - 1; mat[in2][i] && i > 0; i--) {
			    r[in2][i] = r[in2][i + 1] + mat[in2][i];
			}
			for (int i = in3 + 1; mat[in2][i] && i <= m; i++) {
			    l[in2][i] = l[in2][i - 1] + mat[in2][i];
			}
		} else {
            int i, j;
            i = in3, j = in3;
            ll mayor = u[in2][in3];
            ll h = u[in2][in3];
            while (i > 0 && j <= m) {
                if (!u[in2][j] || !u[in2][i]) break;
                if (u[in2][j + 1] > u[in2][i - 1]) j++;
                else i--;
                h = min(h, u[in2][j]);
                h = min(h, u[in2][i]);
                mayor = max(mayor, (j - i + 1) * h);
            }
            i = in3, j = in3;
            h = d[in2][in3];
            mayor = max(mayor, h);
            while (i > 0 && j <= m) {
                if (!d[in2][j] || !d[in2][i]) break;
                if (d[in2][j + 1] > d[in2][i - 1]) j++;
                else i--;
                h = min(h, d[in2][j]);
                h = min(h, d[in2][i]);
                mayor = max(mayor, (j - i + 1) * h);
            }
            i = in2, j = in2;
            h = l[in2][in3];
            mayor = max(mayor, h);
            while (i > 0 && j <= n) {
                if (!l[j][in3] || !l[i][in3]) break;
                if (l[i - 1][in3] > l[j + 1][in3]) i--;
                else j++;
                h = min(h, l[i][in3]);
                h = min(h, l[j][in3]);
                mayor = max(mayor, (j - i + 1) * h);
            }
            i = in2, j = in2;
            h = r[in2][in3];
            mayor = max(mayor, h);
            while (i > 0 && j <= n) {
                if (!r[j][in3] || !r[i][in3]) break;
                if (r[i - 1][in3] > r[j + 1][in3]) i--;
                else j++;
                h = min(h, r[i][in3]);
                h = min(h, r[j][in3]);
                mayor = max(mayor, (j - i + 1) * h);
            }
            cout << mayor << "\n";
		}
	}
	return 0;
}
