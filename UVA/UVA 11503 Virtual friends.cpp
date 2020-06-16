/*
By Progra123 https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ?view_as=subscriber
UVA Online Judge
problem: Virtual Friends (11503)
Section: Chapter 2 Data Structures & algorithms, Union find disjoint sets
link to the problem 
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2498
link to the video where I solve it
https://youtu.be/cCJ4IyjSG24
*/
#include <bits/stdc++.h>
#define vi vector <int>

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
    bool sameset(int u, int v) {return findset(u) == findset(v);}
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
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string in1, in2;
        map <string, int> mapa;
        uf kika(n);
        int cont = 1;
        while (n--) {
            cin >> in1 >> in2;
            if (!mapa[in1]) mapa[in1] = cont++;
            if (!mapa[in2]) mapa[in2] = cont++;
            kika.merge(mapa[in1], mapa[in2]);
            cout << kika.s[kika.findset(mapa[in1])] << "\n";
        }
    }
	return 0;
}
