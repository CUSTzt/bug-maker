#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void getInt(LL &x) {
    x = 0; char ch = getchar(); LL sgn = 1;
    while (!isdigit(ch)) { if (ch == '-') sgn = -1; ch = getchar(); }
    while (isdigit(ch)) { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
    x *= sgn;
}
const LL MAX_N = 50000 + 5;
LL d[MAX_N], a[MAX_N], vis[MAX_N], p[MAX_N], mu[MAX_N], tot;
LL preD[MAX_N], preMu[MAX_N];
void linearSieve() {
    vis[0] = vis[1] = 1; d[1] = 1; mu[1] = 1;
    for (LL i = 2; i <= MAX_N; ++i) {
        if (!vis[i]) {
            p[++tot] = i;
            a[i] = 1; d[i] = 2;
            mu[i] = -1;
        }
        for (LL j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) {
                d[i * p[j]] = d[i] / (a[i] + 1) * (a[i] + 2);
                a[i * p[j]] = a[i] + 1;
                break;
            } else {
                d[i * p[j]] = d[i] * d[p[j]];
                a[i * p[j]] = 1;
                mu[i * p[j]] -= mu[i];
            }
        }
    }
    for (LL i = 1; i < MAX_N; ++i) {
        preD[i] = preD[i - 1] + d[i];
        preMu[i] = preMu[i - 1] + mu[i];
    }
}
inline LL f(LL x) {
    return preD[x];
}
LL T, n, m;
int main() {
    linearSieve();
    getInt(T);
    for (LL cs = 1; cs <= T; ++cs) {
        getInt(n), getInt(m);
        LL l, r, up = min(n, m), ans = 0;
        for (l = 1; l <= up; l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            ans += (preMu[r] - preMu[l - 1]) * f(n / l) * f(m / l);
        }
        printf("%lld\n", ans);
    }
    return 0;
}