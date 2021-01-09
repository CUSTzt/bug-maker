//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
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
#define SZ(a) int(a.size())
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
    int ret = ex_gcd(b, a % b, y, x);
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
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
ll n, k, dp[maxn][2], a[maxn], b[maxn];
ll up(ll *a, int len) {
    ll res = 1, last = 0;
    for (ll i = 1; i <= len; i++) {
        if (a[i] == -1)
            continue;
        else {
            if (i == 1) {
                last = i;
                continue;
            }
            if (!last) {
                res = res * (dp[i - 2][0] + (k - 1) * dp[i - 2][1]) % mod;
            } else {
                if (a[i] == a[last]) {
                    res = res * dp[i - last - 1][0] % mod;
                } else {
                    res = res * dp[i - last - 1][1] % mod;
                }
            }
            last = i;
        }
    }
    if (!last) {
        res = k;
        for (int i = 2; i <= len; i++) {
            res = (res * (k - 1)) % mod;
        }
    } else if (len != last) {
        res = res *
              (dp[len - last - 1][0] + (k - 1) * dp[len - last - 1][1] % mod) %
              mod;
    }
    return res;
}
int main() {
    close;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i & 1)
            cin >> a[(i + 1) >> 1];
        else
            cin >> b[i >> 1];
    }
    dp[0][0] = 0, dp[0][1] = 1;
    for (int i = 1; i <= ((n + 1) >> 1); i++) {
        if (i & 1) {
            dp[i][0] = (1ll * dp[i / 2][0] * dp[i / 2][0] % mod +
                        dp[i / 2][1] * dp[i / 2][1] % mod * (k - 1) % mod) %
                       mod;
            dp[i][1] = (1ll * dp[i / 2][0] * dp[i / 2][1] * 2 % mod +
                        (k - 2) * dp[i / 2][1] % mod * dp[i / 2][1] % mod) %
                       mod;
        } else {
            dp[i][0] = ((k - 1) % mod * dp[i - 1][1] % mod) % mod;
            dp[i][1] = (dp[i - 1][0] + (k - 2) * dp[i - 1][1] % mod) % mod;
        }
    }
    cout << up(a, (n + 1) / 2) * up(b, n - (n + 1) / 2) % mod << endl;
    return 0;
}