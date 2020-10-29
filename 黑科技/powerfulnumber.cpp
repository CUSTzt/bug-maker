// loj 6053
// f(1)=1,f(p^c(次方))=p^c(异或),f(ab)=f(a)f(b)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define SZ 10000099
bool np[SZ];
int ph[SZ], ps[SZ / 10], pn;
void shai() {
    ph[1] = 1;
    for (int i = 2; i < SZ; ++i) {
        if (!np[i]) ps[++pn] = i, ph[i] = i - 1;
        for (int j = 1; j <= pn && i * ps[j] < SZ; ++j) {
            np[i * ps[j]] = 1;
            if (i % ps[j] == 0) {
                ph[i * ps[j]] = ph[i] * ps[j];
                break;
            }
            ph[i * ps[j]] = ph[i] * (ps[j] - 1);
        }
    }
    for (int i = 1; i < SZ; ++i) ph[i] = (ph[i - 1] + ph[i]) % MOD;
}
ll n, u, s[1005];
ll S2(ll a) {
    ll b = a + 1;
    if (a & 1)
        b >>= 1;
    else
        a >>= 1;
    return (a % MOD) * (b % MOD) % MOD;
}
int h[100099][66], d[100099];
ll ans = 0;
void dfs(ll x, ll v, int w) {
    ans = (ans + v * ((n / x < SZ) ? ph[n / x] : s[n / (n / x)])) % MOD;
    if (w > 1 && x > n / ps[w] / ps[w]) return;
    for (int s = w; s <= pn; ++s) {
        if (s > 1 && x * ps[s] * ps[s] > n) break;
        ll y = x * ps[s];
        for (int j = 1; y <= n; ++j, y *= ps[s]) {
            if (d[s] < j) {
                ++d[s];
                ll F = ps[s] ^ j, G = ps[s] - 1;
                for (int k = 1; k <= j; ++k)
                    F = (F - G % MOD * h[s][j - k]) % MOD, G *= ps[s];
                h[s][j] = F;
            }
            if (!h[s][j]) continue;
            dfs(y, v * h[s][j] % MOD, s + 1);
        }
    }
}
int main() {
    for (int i = 0; i <= 100000; ++i) h[i][0] = 1;
    shai();
    cin >> n;
    u = 1;
    while (n / u >= SZ) ++u;
    for (int i = u; i >= 1; --i) {
        // s[i]=phi(n/i)
        ll t = n / i, a = 2, b, p;
        s[i] = S2(t);
        for (; a <= t; a = b + 1)
            p = t / a, b = t / p,
            s[i] = (s[i] - (b - a + 1) % MOD * ((p < SZ) ? ph[p] : s[b * i])) % MOD;
    }
    dfs(1, 1, 1);
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << "\n";
}