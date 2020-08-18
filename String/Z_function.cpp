#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 7;
int n, m, z[N], p[N];
char a[N], b[N];

void Z(char *s, int n) {  // 单个串 z[i] = lcp(s[1],s[i]) 从1开始
    for (int i = 1; i <= n; i++) z[i] = 0;
    z[1] = n;
    for (int i = 2, l = 0, r = 0; i <= n; i++) {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] <= n && s[i + z[i]] == s[z[i] + 1]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
}

void exkmp(char *s, int n, char *t, int m) {  // 两个串之间
    Z(t, m);
    for (int i = 1; i <= n; i++) p[i] = 0;
    for (int i = 1, l = 0, r = 0; i <= n; i++) {
        if (i <= r) p[i] = min(z[i - l + 1], r - i + 1);
        while (i + p[i] <= n && s[i + p[i]] == t[p[i] + 1]) ++p[i];
        if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
    }
}

int main() {
    scanf("%s%s", a + 1, b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);
    exkmp(a, n, b, m);
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        ans ^= (1ll * i * (z[i] + 1));
    }
    cout << ans << endl;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        ans ^= (1ll * i * (p[i] + 1));
    }
    cout << ans << endl;
    return 0;
}