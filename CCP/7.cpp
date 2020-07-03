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
 
    string s;
    cin >> s;
    int n = s.size();
    int m = 0;
    int fac = 1;
    while (fac * m <= n) {m++; fac <<= 1;}
    m--;
    fac >>= 1;
    map <string, int> kika;
    while (1) {
        bool band = true;
        int i;
        int temp = fac * m;
        for (i = 0; i <= n - temp; i++) {
            int j = i;
            string t;
            band = true;
            kika.clear();
            for (j = i; j < i + temp; j++) {
                t += s[j];
                if (t.size() == m) {
                    if (kika[t]) {band = false; break;}
                    kika[t]++;
                    t.resize(0);
                }
            }
            if (band) break;
        }
        if (band) {
            cout << m << " " << i << "\n";
            break;
        }
        fac >>= 1;
        m--;
    }
	return 0;
}
