#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define int long long
#define FOR(i, x, y) \
    for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) \
    for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
const int MOD = 1e9 + 7, mod = 1e9 + 7;
const int M = 1e6 + 10;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
LL invf[M], fac[M] = {1};
void fac_inv_init(LL n, LL p) {  //调用fac_inv_init(MOD,MOD);
    FOR(i, 1, n)
    fac[i] = i * fac[i - 1] % p;
    invf[n - 1] = bin(fac[n - 1], p - 2, p);
    FORD(i, n - 2, -1)
    invf[i] = invf[i + 1] * (i + 1) % p;
}
inline LL C(LL n, LL m) {  // n >= m >= 0
    return n < m || m < 0 ? 0 : fac[n] * invf[m] % MOD * invf[n - m] % MOD;
}
LL Lucas(LL n, LL m) {  // m >= n >= 0
    return m ? C(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD : 1;
}
struct Point {
    int x, y;
} p[5000];
bool cmp(Point a, Point b) { return a.x == b.x ? a.y < b.y : a.x < b.x; } //这个是关键！！
int h, w, n, dp[5000], x, y;
int32_t main() {
    memset(dp, 0, sizeof dp);
    fac_inv_init(M, MOD);
    cin >> h >> w >> n;
    h--, w--;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].x--, p[i].y--;
    }
    sort(p + 1, p + 1 + n, cmp);
    p[++n].x = h;
    p[n].y = w;
    for (int i = 1; i <= n; i++) {
        dp[i] = C(p[i].x + p[i].y, p[i].x);
        for (int j = 1; j < i; j++) {
            int tmp = C(p[i].x + p[i].y - p[j].x - p[j].y, p[i].x - p[j].x);
            dp[i] = (dp[i] + mod - dp[j] * tmp % mod) % mod;
        }
    }
    cout << dp[n] << endl;
}