/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
Omegaup.com
Problem: Bloques Cayendo
Section: first CCP (Copa Centroamericana de Programacion)
link to the problem 
https://omegaup.com/arena/ccp-2020-public/#problems (link to the contest)
https://omegaup.com/arena/problem/1er-ccp-bloques/#problems (link to the problem)
link to the video where I solve it:
https://youtu.be/I3iJc7wzi9o
*/
#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

typedef vector <int> vi;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
    int in;
    char mat[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mat[i][j] = '.';
        }
    }
    vi mayor(10, 0);
    for (int i = 0; i < n; i++) {
        cin >> in;
        int temp = max(mayor[in], mayor[in + 1]);
        mat[temp][in] = mat[temp][in + 1] = mat[temp + 1][in] = mat[temp + 1][in + 1] = '#';
        mayor[in] = mayor[in + 1] = temp + 2;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            cout << mat[i][j];
        }
        cout << "\n";
    }
	return 0;
}
