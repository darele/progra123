/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Omegaup.com
Problem: Islotes
Section: first CCP (Copa Centroamericana de Programacion)
link to the problem 
https://omegaup.com/arena/ccp-2020-public/#problems (link to the contest)
https://omegaup.com/arena/problem/Islotes/#problems (link to the problem)
link to the video where I solve it:
https://youtu.be/I3iJc7wzi9o
*/
#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    string s;
    cin >> s;
    int n = s.size();
    int cont = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i + 1] == s[i - 1] && s[i] != s[i - 1]) cont++;
    }
    cout << cont << "\n";
	return 0;
}
