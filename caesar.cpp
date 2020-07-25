/*
By progra123
https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ
Caesar Cipher algorithm
C++ implementation
*/

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

string ceasar(string s, int t) {
	t = (t % 26) % 26;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] > 'z' || s[i] < 'a') continue;
		s[i] = (s[i] - 'a' + t) % 26 + 'a';
	}
	return s;
}

int main() {

	string s, temp;
	while (!cin.eof()) {
		getline(cin, temp);
		s += temp;
		s += '\n';
	}
	//for (int i = 1; i < 26; i++) {
		temp = ceasar(s, 10);
		cout << temp << "\n";
	//}
	return 0;
}
