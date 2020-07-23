/*
https://csacademy.com/contest/interview-archive/task/find-any-duplicate/
*/

int findDuplicate(const vector<int>& v) {
    int n = v.size();
    int h, t;
    t = 0;
    h = 2;
    h %= n;
    while (v[h] != v[t]) {
        t++;
        h += 2;
        h %= n;
        t %= n;
    }
    if (h != t) return v[h];
    t = 1;
    h = 3;
    t %= n;
    h %= n;
    while (v[h] != v[t]) {
        t++;
        h += 2;
        h %= n;
        t %= n;
    }
    return v[h];
}
