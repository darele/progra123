/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
atcoder.jp
Problem: Decayed Bridges
section: abc 120
link to the problem 
https://atcoder.jp/contests/abc120/tasks/abc120_d
link to the video where I solve it:
https://youtu.be/7x7FBEGXjK4
*/
#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define ii pair <ll, ll>
#define vii vector <ii>

using namespace std;

bool comp(ll a, ll b) {
	return a > b;
}

ll sum;

class uf {
public:
    vi p;
    vl s;
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
        sum -= (s[x] * s[y]);
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
 
    ll n, m;
    cin >> n >> m;
    int in1, in2;
    ii arr[m];
    for (int i = 0; i < m; i++) {
        cin >> in1 >> in2;
        arr[i] = {in1, in2};
    }
    vl ans;
    ans.reserve(m);
    sum = (n * (n - 1)) / 2;
    ans.push_back(sum);
    uf s(n);
    for (int i = m - 1; i > 0; i--) {
        s.merge(arr[i].first, arr[i].second);
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for (ll x : ans) {
        cout << x << "\n";
    }
	return 0;
}
