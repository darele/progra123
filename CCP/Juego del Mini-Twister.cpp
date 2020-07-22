/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Omegaup.com
Problem: Juego del Mini-Twister
Section: first CCP (Copa Centroamericana de Programacion)
link to the problem 
https://omegaup.com/arena/1er-ccp/#problems (link to the contest)
https://omegaup.com/arena/problem/1er-ccp-tapete/#problems
link to the video where I solve it:
https://youtu.be/I3iJc7wzi9o
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
    pair <int, int> mat[n * n + 5];
    int in;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> in;
            mat[in] = {i, j};
        }
    }
    int cont = 0;
    for (int i = 2; i <= (n * n); i++) {
        cont += (abs(mat[i].first - mat[i - 1].first) + abs(mat[i].second - mat[i - 1].second));
    }
    cout << cont << "\n";
	return 0;
}
