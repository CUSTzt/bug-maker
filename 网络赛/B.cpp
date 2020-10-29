//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
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
bool ispow(ll n) {
    if (n == 1) return 0;
    return (n & (n - 1)) == 0;
}
// whzzt 是不是质数，不是质数输出最大质因子。  n^1/4
using i64 = long long;
using i128 = __int128;
i64 fpow(i64 a, i64 t, i64 mod) {
    i64 r = 1;
    for (; t; t >>= 1, a = (i128)a * a % mod) {
        if (t & 1) {
            r = (i128)r * a % mod;
        }
    }
    return r;
}
i64 gcd(i64 a, i64 b) {
#define ctz __builtin_ctzll
    int shift = ctz(a | b);
    b >>= ctz(b);
    while (a) {
        a >>= ctz(a);
        if (a < b) swap(a, b);
        a -= b;
    }
    return b << shift;
}
bool check_prime(i64 n) {
    static const int jp[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    if (n == 1) return false;
    for (int p : jp)
        if (n % p == 0) return n == p;
    i64 r = n - 1, x, y;
    int e = 0;
    while (~r & 1) r >>= 1, ++e;
    for (int p : jp) {
        x = fpow(p, r, n);
        for (int t = 0; t < e && x > 1; ++t) {
            y = (i128)x * x % n;
            if (y == 1 && x != n - 1) return false;
            x = y;
        }
        if (x != 1) return false;
    }
    return true;
}
i64 find(i64 n) {
    static const int step = 1 << 7;
    i64 x, y = rand() % n;
    int c = rand() % n;
    auto f = [=](i64 x) { return ((i128)x * x + c) % n; };
    for (int l = 1;; l <<= 1) {
        x = y;
        for (int i = 0; i < l; ++i) y = f(y);
        for (int k = 0; k < l; k += step) {
            int e = std::min(step, l - k);
            i64 g = 1, z = y;
            for (int i = 0; i < e; ++i) g = (i128)g * ((y = f(y)) + n - x) % n;
            g = gcd(g, n);
            if (g == 1) continue;
            if (g == n)
                for (g = 1, y = z; g == 1;) y = f(y), g = gcd(y + n - x, n);
            return g;
        }
    }  //
}
void rho(i64 n, map<i64, int> &factor) {
    while (~n & 1) n >>= 1, ++factor[2];
    if (n == 1) return;
    if (check_prime(n)) {
        ++factor[n];
        return;
    }
    i64 d;
    for (d = find(n); d == n; d = find(d))
        ;
    rho(d, factor), rho(n / d, factor);
}
int T;
i64 n;
void up() {
    int cnt = 0, n;
    cin >> n;
    int flag = 0;
    vi fk;
    for (int i = 1; i <= n; i++) {
        map<i64, int> f;
        int x;
        cin >> x;
        if (x == 1) {
            continue;
        }
        rho(x, f);
        int fl = 0;
        while (x % 2 == 0) x /= 2, fl = 1;
        if (x == 1) {
            fk.eb(1);
            continue;
        }
        x = fl;
        for(auto i : f){
            x += i.se;
        }
        fk.eb(x);
    }
    int ans = 0;
    for(auto i : fk){
        ans ^= i;
    }
    cout << (ans ? "W" : "L") << endl;
    return;
}
int main() {
    close;
    CASET { up(); }
    return 0;
}