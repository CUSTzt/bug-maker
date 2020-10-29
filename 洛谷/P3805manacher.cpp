#include <bits/stdc++.h>
using namespace std;
const int N = 3e7;
int n, m, i, r, p, f[N], g[N];
char a[N], s[N];
int min(int a, int b) { return a < b ? a : b; }
void up(int& a, int b) {
    if (a < b) a = b;
}
int main() {
    scanf("%s", a + 1), n = strlen(a + 1);
    for (i = 1; i <= n; i++) s[i << 1] = a[i], s[i << 1 | 1] = '#';
    s[0] = '$', s[1] = '#', s[m = (n + 1) << 1] = '@';
    for (r = p = 0, f[1] = 1, i = 2; i < m; i++) {
        for (f[i] = r > i ? min(r - i, f[p * 2 - i]) : 1;
             s[i - f[i]] == s[i + f[i]]; f[i]++)
            ;
        if (i + f[i] > r) r = i + f[i], p = i;
    }
    for (i = 0; i <= m; i++) g[i] = 0;
    for (i = 2; i < m; i++) up(g[i - f[i] + 1], i + 1);
    for (i = 1; i <= m; i++) up(g[i], g[i - 1]);
    int ans = 0;

    for (i = 2; i < m; i += 2) up(ans, g[i] - i);
    // printf("%d ", g[i]-i);
    cout << ans << endl;
}
