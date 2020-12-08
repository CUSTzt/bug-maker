//~ while (CloCk()<=69*CLOCKS_PER_SEC)
//~ #pragma Comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
//target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int32_t(a.size())
#define ALL(x) (x).begin(), (x).end()
#define trav(a, x) for (auto &a : x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c)         \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET    \
    int ___T;    \
    cin >> ___T; \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr int mod = 998244353;
constexpr int Erica = 998244353;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll ret = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
int norm(int x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline ll get_inv(ll a) {
    ll x, y;
    ex_gcd(a, mod, x, y);
    return norm(x + mod);
}
template <class T>
inline void umin(T &x, T y) {
    x = x > y ? y : x;
}
template <class T>
inline void umax(T &x, T y) {
    x = x < y ? y : x;
}
template <class T>
inline void dec(T &x, T y) {
    x -= y;
    if (x < 0) x += mod;
}
template <class T>
inline void add(T &x, T y) {
    x += y;
    if (x >= mod) x -= mod;
}
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
constexpr int maxn =
    3e6 + 10;  // remember to calculate. if tle, check maxn first.
LL invf[maxn], fac[maxn];
void fac_inv_init(LL n, LL p) {
    fac[0] = 1;
    FOR(i, 1, n)
    fac[i] = i * fac[i - 1] % p;
    invf[n - 1] = bin(fac[n - 1], p - 2, p);
    FORD(i, n - 2, -1)
    invf[i] = invf[i + 1] * (i + 1) % p;
}
inline LL C(LL n, LL m) {  // n >= m >= 0
    return n < m || m < 0 ? 0 : fac[n] * invf[m] % mod * invf[n - m] % mod;
}
ll a, b, p, q, pw1[maxn], pw2[maxn], f[maxn], ans, A[maxn];
int main() {
    close;
    fac_inv_init(maxn, Erica);
    cin >> a >> b >> p;
    b++;
    q = (1 - p + mod) % mod;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < maxn; i++)
        pw1[i] = 1ll * pw1[i - 1] * p % mod,
        pw2[i] = 1ll * pw2[i - 1] * q % mod;
    for (int i = 1 - b; i <= b - 1; i++)
        A[i + b] = 1ll * p *
                   bin(mod + 1 - 1ll * A[i + b - 1] * q % mod, mod - 2, mod) %
                   mod;
    f[b * 2] = 1;
    for (int i = b - 1; i >= -b; i--)
        f[i + b] = 1ll * f[i + b + 1] * A[i + b] % mod;
    for (int i = 0; i < a; i++)
        if (a - i < b)
            add(ans, 1ll * C(a + i - 1, i) * pw1[i] % mod * pw2[a] % mod *
                         f[i - a + b] % mod);
    for (int i = 0; i < a; i++)
        if (a - i < b)
            add(ans, 1ll * C(a + i - 1, i) * pw1[a] % mod * pw2[i] % mod *
                         f[a - i + b] % mod);
        else
            add(ans, 1ll * C(a + i - 1, i) * pw1[a] % mod * pw2[i] % mod);
    cout << ans << endl;
    return 0;
}