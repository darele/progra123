#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <dl>
#define graph vector <vi>
#define inf 100000000

using namespace std;

bool prime(int n) {
	if (n == 1 || n == 0) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
	return true;
}

int r(int n) {
	int div = 1;
	int ans = 0;
	while (div <= n) {
		ans *= 10;
		ans += ((n / div) % 10);
		div *= 10;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int cont = 0;
	int i = 11;
	while (cont < n) {
		if (prime(i)) {
			int x = r(i);
			if (x != i && prime(x)) {
				cont++;
				if (cont == n) cout << i << "\n";
			}
		}
		i++;
	}
}
