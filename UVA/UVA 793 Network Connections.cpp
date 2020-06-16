/*
By Progra123 (https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ?view_as=subscriber)
UVA Online Judge
problem: Network Connections (793)
Section: Chapter 2 Data Structures & algorithms, Union find disjoint sets
link to the problem 
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=734
link to the video where I solve it:
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
        uf kika(n);
        int in1, in2;
        char c;
        int buenas = 0;
        int q = 0;
        string entrada;
        getline(cin, entrada);
        while (1) {
            getline(cin, entrada);
            if (entrada.size() == 0) break;
            istringstream temp(entrada);
            temp >> c >> in1 >> in2;
            if (c == 'c') kika.merge(in1, in2);
            else {
                if (kika.sameset(in1, in2)) buenas++;
                q++;
            }
        }
        cout << buenas << "," << q - buenas << "\n";
        if (t) cout << "\n";
    }
	return 0;
}
