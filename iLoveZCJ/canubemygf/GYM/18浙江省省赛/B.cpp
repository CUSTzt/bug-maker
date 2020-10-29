#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
const int Inf = 0x3f3f3f3f;
const ll Linf = 0x7f7f7f7f7f7f7f7f;
const int MAXN = 2e5;
char buf[100000], *p1 = buf, *p2 = buf;
inline char nc() {
    return p1 == p2 &&
                   (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
               ? EOF
               : *p1++;
}
inline int read() {
    int w = 1, data = 0;
    char ch = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = nc();
    if (ch == '-') w = -1, ch = nc();
    while ('0' <= ch && ch <= '9') data = data * 10 + ch - '0', ch = nc();
    return w * data;
}
int n, d[MAXN], s[MAXN];
void doit() {
    n = read();
    for (int i = 1; i <= n; i++) d[i] = read();
    for (int i = 1; i <= n; i++) s[i] = read();
    map<int, int> mp;
    int ans = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        mp[s[i] - d[i]]++;
        mx = max(mx, mp[s[i] - d[i]]);
    }
    printf("%d\n", mx);
}
int main() {
    //    freopen("input.txt", "r", stdin);
    int _ = read();
    while (_--) doit();
    return 0;
}