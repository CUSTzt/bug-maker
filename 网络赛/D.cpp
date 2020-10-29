#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
// return the sum of p^k for all p <= m, where m is in form floor(n / i)
// for m <= sqrt{n}, stored in ssum[m]; for m > sqrt{n} stored in lsum[n / m]
// note: if you need all correct value of ssum and lsum, please remove ”mark”
// and make ”delta” always be 1
inline ll sub_mod(ll x, ll y, ll mod) { return (x-y + mod) % mod; }
inline ll mul_mod(ll a, ll b, ll mod) {
    if (mod < int(2e9)) return a * b % mod;
    ll k = (ll)((long double)a * b / mod);
    ll res = a * b-k * mod;
    res %= mod;
    if (res < 0) res += mod;
    return res;
}
inline ll pow_mod(ll a, ll n, ll m) {
    ll res = 1;
    for (a %= m; n; n >>= 1) {
        if (n & 1) res = mul_mod(res, a, m);
        a = mul_mod(a, a, m);
    }
    return res;
}
pair<vector<ll>, vector<ll>> prime_count(ll n, ll k, ll mod) {
    auto pow_sum = [](ll n, ll k, ll mod) {
        if (k == 0) return n;
        if (k == 1) return n * (n + 1) / 2 % mod;
    };
    const ll v = static_cast<ll>(sqrt(n));
    vector<ll> ssum(v + 1), lsum(v + 1);
    vector<bool> mark(v + 1);
    for (int i = 1; i <= v; ++i) {
        ssum[i] = pow_sum(i, k, mod)-1;
        lsum[i] = pow_sum(n / i, k, mod)-1;
    }
    for (ll p = 2; p <= v; ++p) {
        if (ssum[p] == ssum[p-1]) continue;
        ll psum = ssum[p-1], q = p * p, ed = min(v, n / q);
        ll pk = pow_mod(p, k, mod);
        int delta = (p & 1) + 1;
        for (int i = 1; i <= ed; i += delta)
            if (!mark[i]) {
                ll d = i * p;
                if (d <= v) {
                    lsum[i] = sub_mod(
                        lsum[i], sub_mod(lsum[d], psum, mod) * pk % mod, mod);
                } else {
                    lsum[i] = sub_mod(
                        lsum[i], sub_mod(ssum[n / d], psum, mod) * pk % mod,
                        mod);
                }
            }
        for (ll i = q; i <= ed; i += p * delta) mark[i] = 1;
        for (ll i = v; i >= q;--i) {
            ssum[i] = sub_mod(ssum[i],
                             sub_mod(ssum[i / p], psum, mod) * pk % mod, mod);
        }
    }
    return {move(ssum), move(lsum)};
}
int main() {
    ll n, k, mod;
    k = 1;
    scanf("%lld %lld", &n, &mod);
    auto it = prime_count(n, k, mod);
    printf("%lld", it.second[1]);
}
