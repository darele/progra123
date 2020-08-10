/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Codeforces.com
Problem: Valid BFS?
section: Manthan Codefest 18
link to the problem 
https://codeforces.com/contest/1037/problem/D
link to the video where I solve it:
https://youtu.be/Rux6TJqNbIY
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vector <int> >
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    int in1, in2;
    graph grafo(n + 5, vi());
    vi p(n + 5, 0);
    int lista[n];
    for (int i = 1; i < n; i++) {
        cin >> in1 >> in2;
        grafo[in1].push_back(in2);
        grafo[in2].push_back(in1);
    }
    for (int i = 0; i < n; i++) cin >> lista[i];
    int t = 0;
    for (int v : grafo[1]) {
        p[v] = 1;
    }
    for (int i = 1; i < n; i++) {
        while (t < i && lista[t] != p[lista[i]]) t++;
        if (t == i) {
            cout << "No\n";
            return 0;
        }
        for (int v : grafo[lista[i]]) p[v] = lista[i];
    }
    cout << "Yes\n";
	return 0;
}
