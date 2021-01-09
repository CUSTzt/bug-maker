#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 10001
int a[N], d;
ll f[N][101];
ll dfs(int len, int pre, int top) {
    if (!len) return pre == 0;
    if (!top && f[len][pre] != -1) return f[len][pre];
    int up = top ? a[len] : 9;
    ll num = 0;
    for (int i = 0; i <= up; i++)
        num = (num + dfs(len - 1, (pre + i) % d, top && (i == up))) % mod;
    if (!top) f[len][pre] = num;
    return num;
}
char c[N];
int main() {
    memset(f, -1, sizeof(f));
    scanf("%s%d", c + 1, &d);
    int n = strlen(c + 1);
    for (int i = n, j = 1; i; i--, j++) a[j] = c[i] - '0';
    cout << (dfs(n, 0, 1) - 1 + mod) % mod << endl;
    return 0;
}