
#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <vii> graph;

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
    vii punto(n);
    int in1, in2;
    for (int i = 0; i < n; i++) {
        cin >> in1 >> in2;
        punto[i] = {in1, in2};
    }
    sort(punto.begin(), punto.end());
    pair <int, int> temp;
    temp = {punto[n - 1].first + 1, punto[n - 1].second + 1};
    int cont = 0;
    int my = -1;
    for (int i = n - 1; i >= 0; i--) {
        in1 = punto[i].first, in2 = punto[i].second;
        if (in1 == temp.first) continue;
        else {
            if (in2 > my) {
                cont++;
                my = in2;
            }
            temp = {in1, in2};
        }
    }
    cout << cont << "\n";
	return 0;
}
