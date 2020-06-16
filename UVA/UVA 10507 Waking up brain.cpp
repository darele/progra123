/*
By Progra123 (https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ?view_as=subscriber)
UVA Online Judge
problem: Waking up Brain (10507)
Section: Chapter 2 Data Structures & algorithms, Union find disjoint sets
link to the problem 
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=17&page=show_problem&problem=1448
link to the video where I solve it
https://youtu.be/cCJ4IyjSG24
*/
#include <bits/stdc++.h>
#define vi vector <int>
#define graph vector <vi>

using namespace std;

class uf {
public:
    vi p;
    vi s;
    uf (int n) {
        p.resize(n + 5);
        s.assign(n + 5, 1);
        for (int i = 0; i < n + 5; i++) p[i] = i;
    }
    int findset(int u) {return u == p[u] ? u : p[u] = findset(p[u]);}
    void merge(int u, int v) {
        int x = findset(u);
        int y = findset(v);
        if (x == y) {
            return;
        }
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
 
    while (1) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        if (cin.eof()) break;
        uf kika(26);
        vector <bool> d(30);
        graph grafo;
        grafo.assign(30, vi());
        char in1, in2, r;
        cin >> in1;
        r = in1;
        r -= 'A';
        d[in1 - 'A'] = 1;
        cin >> in2;
        d[in2 - 'A'] = 1;
        kika.merge(in1 - 'A', in2 - 'A');
        cin >> in2;
        d[in2 - 'A'] = 1;
        kika.merge(in1 - 'A', in2 - 'A');
        for (int i = 0; i < m; i++) {
            cin >> in1 >> in2;
            in1 -= 'A';
            in2 -= 'A';
            grafo[in1].push_back(in2);
            grafo[in2].push_back(in1);
        }
        int cont = -1;
        while (1) {
            cont++;
            vi temp;
            temp.reserve(26);
            for (int i = 0; i < 26; i++) {
                if (d[i]) continue;
                int c = 0;
                for (int v : grafo[i]) {
                    if (d[v]) c++;
                }
                if (c >= 3) temp.push_back(i);
            }
            if (temp.size()) {
                for (int x : temp) {
                    d[x] = 1;
                    kika.merge(r, x);
                }
                continue;
            }
            break;
        }
        if (kika.s[kika.findset(r)] == n) {
            cout << "WAKE UP IN, " << cont << ", YEARS\n";
        } else {
            cout << "THIS BRAIN NEVER WAKES UP\n";
        }
    }
	return 0;
}
