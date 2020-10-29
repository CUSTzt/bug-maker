//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
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
// using LL = long long;
#define LL long long 
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
constexpr int mod = 1e9 + 7;
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
    1e6 + 10;  // remember to calculate. if tle, check maxn first.
ll n, P;
int m;
ll w[10];
ll quick(ll x, ll y, ll mod) {
    ll res = 1ll;
    while (y) {
        if (y & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
ll find(ll n, ll p, ll mod) {
    if (!n) {
        return 1ll;
    }
    ll res = 1ll;
    for (ll i = 2; i <= mod; i++) {
        if (i % p) {
            res *= i, res %= mod;
        }
    }
    res = quick(res, n / mod, mod);
    for (ll i = 2; i <= n % mod; i++) {
        if (i % p) {
            res *= i, res %= mod;
        }
    }
    return res * find(n / p, p, mod) % mod;
}
ll inv(ll n, ll mod, ll p) {
    ll phi = mod - (mod / p);
    return quick(n, phi - 1, mod);
}
ll CRT(ll b, ll mod, ll p) {
    return b * inv(P / mod, mod, p) % P * (P / mod) % P;
}
ll C(ll n, int m, ll p, ll mod) {
    ll res = find(n, p, mod);
    ll k = 0;
    for (ll i = n; i; i /= p) {
        k += i / p;
    }
    for (int i = 1; i <= m; i++) {
        res *= inv(find(w[i], p, mod), mod, p), res %= mod;
        for (ll j = w[i]; j; j /= p) {
            k -= j / p;
        }
    }
    return res * quick(p, k, mod) % mod;
}
ll ex_lucas(ll n, int m) {
    ll res = 0;
    ll sum = P;
    ll mod;
    for (int i = 2; 1ll * i * i <= P; i++) {
        if (sum % i == 0) {
            mod = 1ll;
            while (sum % i == 0) {
                mod *= i;
                sum /= i;
            }
            res += CRT(C(n, m, i, mod), mod, i), res %= P;
        }
    }
    if (sum != 1) {
        res += CRT(C(n, m, sum, sum), sum, sum), res %= P;
    }
    return res;
}
int main() {
    scanf("%lld", &P);
    scanf("%lld%d", &n, &m);
    ll sum = n;
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &w[i]);
        sum -= w[i];
    }
    if (sum < 0) {
        printf("Impossible");
        return 0;
    }
    w[++m] = sum;
    printf("%lld", ex_lucas(n, m));
}