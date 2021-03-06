/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
USACO.org
Problem: Social Distancing I
section: US OPEN 2020
link to the problem 
http://www.usaco.org/index.php?page=viewproblem2&cpid=1035
link to the video where I solve it:
https://youtu.be/67J5FfEiVNc
*/
#include <bits/stdc++.h>
#define cin fin //comment this line to test your code with stdin
#define cout fout //comment this line to test your code with stdout

using namespace std;

ifstream fin("socdist1.in");
ofstream fout("socdist1.out");

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int ini, fin, cont;
  priority_queue <int> cola;
  ini = fin = cont = 0;
  int i = 0;
  while (i < n && s[i] == '0') {ini++; i++;}
  if (i == n) {cout << n - 1 << "\n"; return 0;}
  n--;
  while (s[n] == '0') {fin++; n--;}
  n++;
  for (i++; i < n; i++) {
    if (s[i] == '0') cont++;
    else {
      if (cont == 0) {cout << "1\n"; return 0;}
      cola.push(cont);
      cont = 0;
    }
  }
  int d, d2;
  int temp;
  if (cola.empty()) temp = 0;
  else temp = cola.top();
  d = max(ini / 2, max(fin / 2, ((temp - 2) / 3) + 1));
  temp = (temp + 1) / 2;
  if (ini >= temp && ini >= fin) {
    d2 = ini;
    ini = 0;
  } else if (fin >= ini && fin >= temp) {
    d2 = fin;
    fin = 0;
  } else {
    d2 = temp;
    cola.pop();
  }
  if (!cola.empty()) temp = cola.top();
  else temp = 0;
  temp = (temp + 1) / 2;
  if (ini >= temp && ini >= fin) {
    d2 = min(ini, d2);
    ini = 0;
  } else if (fin >= ini && fin >= temp) {
    d2 = min(fin, d2);
    fin = 0;
  } else {
    d2 = min(temp, d2);
  }
  d2 = max(d, d2);
  while (!cola.empty()) {
    d2 = min(cola.top() + 1, d2);
    cola.pop();
  }
  cout << d2 << endl;
  return 0;
}
