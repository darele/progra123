/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
USACO.org
Problem: Social Distancing I
section: US OPEN 2020
link to the problem 
http://www.usaco.org/index.php?page=viewproblem2&cpid=1036
link to the video where I solve it:
https://youtu.be/y4xFNi2xtDk
*/
#include <bits/stdc++.h>
#define tam 10000000
#define cin fin
#define cout fout

using namespace std;

ifstream fin("socdist2.in");
ofstream fout("socdist2.out");

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	pair <int, bool> arr[n];
	int in1, in2;
	for (int i = 0; i < n; i++) {
	    cin >> in1 >> in2;
	    arr[i] = {in1, in2};
	}
	if (n == 1) {
	    if (arr[0].second) cout << "1\n";
	    else cout << "0\n";
	    return 0;
	}
	sort(arr, arr + n);
	int r = tam;
	for (int i = 1; i < n - 1; i++) {
	    if (!arr[i].second) {
	        if (arr[i + 1].second) {
	            r = min(r, arr[i + 1].first - arr[i].first - 1);
	        }
	        if (arr[i - 1].second) {
	            r = min(r, arr[i].first - arr[i - 1].first - 1);
	        }
	    }
	}
	if (!arr[0].second) {
	    if (arr[1].second) {
	        r = min(r, arr[1].first - arr[0].first);
	    }
	}
	if (!arr[n - 1].second) {
	    if (arr[n - 2].second) {
	        r = min(r, arr[n - 1].first - arr[n - 2].first);
	    }
	}
	int cont = 0;
	int i;
	for (i = 0; i < n - 1; i++) {
	    if (arr[i].second) {
	        while (i < n && arr[i + 1].first - arr[i].first <= r) i++;
	        cont++;
	    }
	}
	if (i == n - 1 && arr[i].second) cont++;
	cout << cont << "\n";
	return 0;
}
