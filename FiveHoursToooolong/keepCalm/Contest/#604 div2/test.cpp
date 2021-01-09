#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 2e5 + 7;
int v[maxn], n, q;
long long p[maxn], t[maxn], s[maxn], inv[maxn];
set<long long> S;
long long quickpow(long long m, long long n)  //返回m
{
    long long b = 1;
    while (n > 0) {
        if (n & 1) b = (b * m) % mod;
        n = n >> 1;
        m = (m * m) % mod;
    }
    return b % mod;
}
long long query(int l, int r) {
    if (l == 1) {
        long long A = (t[r - 1] + 1) % mod;
        long long B = s[r] % mod;
        return A * quickpow(B, mod - 2) % mod;
    }
    long long A =
        (t[r - 1] - t[l - 2] + mod) % mod * quickpow(s[l - 1], mod - 2) % mod;
    long long B = s[r] * quickpow(s[l - 1], mod - 2) % mod;
    // cout << "A == " << A << "  B === " << B << endl;
    return A * quickpow(B, mod - 2) % mod;
}
int main() {
    scanf("%d%d", &n, &q);
    S.insert(1);
    S.insert(n + 1);
    v[1] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] = p[i] * quickpow(100, mod - 2) % mod;
    }
    s[0] = 1;
    t[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] * p[i] % mod;
        t[i] = (t[i - 1] + s[i]) % mod;
    }
    for(int i = 1; i <= n; i++){
        printf("s[%d]==%lld  t[%d]==%lld\n",i,s[i],i,t[i]);
    }
    long long ans = query(1, n);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (v[x]) {
            v[x] = 0;
            S.erase(x);
            auto L = S.lower_bound(x);
            auto R = L;
            L--;
            ans = (ans + query(*L, *R - 1)) % mod;
            ;
            ans = (ans - query(*L, x - 1) + mod) % mod;
            ans = (ans - query(x, *R - 1) + mod) % mod;
        } else {
            v[x] = 1;
            auto L = S.lower_bound(x);
            auto R = L;
            L--;
            ans = (ans - query(*L, *R - 1) + mod) % mod;
            ;
            ans = (ans + query(*L, x - 1)) % mod;
            ans = (ans + query(x, *R - 1)) % mod;
            S.insert(x);
        }
        cout << ans << endl;
    }
}