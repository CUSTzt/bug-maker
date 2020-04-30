#include <bits/stdc++.h>
using namespace std;
static auto faster_iostream = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
typedef long long ll;
const int N = 1e3 + 5, M = 1e9 + 7;
ll qpow(ll x, ll n) {
    ll res = 1;
    for (; n; n >>= 1, x = x * x % M)
        if (n & 1) res = res * x % M;
    return res;
}

ll fac[N];

ll comb(ll n, ll m) {
    return fac[n] * qpow(fac[m] * fac[n - m] % M, M - 2) % M;
}

int main() {
    int n, k;
    cin >> n >> k;

    fac[0] = fac[1] = 1;
    for (int i = 2; i <= max(n, k); i++) {
        fac[i] = fac[i - 1] * i % M;
    }
    ll ans = 0;
    for (int i = 0; i <= min(n - 1, k - 1); i++) {
        ans += comb(n - 1, i) * comb(k, i + 1) % M * fac[i + 1] % M;
        ans %= M;
    }
    cout << ans << '\n';
}
