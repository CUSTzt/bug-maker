//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
// #pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
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
#define int long long
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
constexpr ll mod = 1e9 + 9;
constexpr ll Erica = 1e9 + 9;
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
int bin(int x, int n, int MOD) {
    int ret = MOD != 1;
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
constexpr int maxn = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
constexpr ll fuck1 = 691504013, fuck2 = 308495997;
int fac[maxn], A[maxn], B[maxn];
ll n, k, cc;
void INIT() {
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = 1ll * fac[i - 1] * i % Erica;
    }
    A[0] = B[0] = 1;
    for (int i = 1; i < maxn; i++) {
        A[i] = 1ll * A[i - 1] * fuck1 % mod;
        B[i] = 1ll * B[i - 1] * fuck2 % mod;
    }
}
// ll m = get_inv(383008016,mod);
ll zhuangba = get_inv(383008016, mod);
ll solve(ll n, ll k) {
    ll ans = 0;
    for (int r = 0; r <= k; r++) {
        ll t = A[k - r] * B[r] % mod;
        t = bin(t, cc, mod);
        ll x = fac[k];
        ll y = fac[k - r] * fac[r] % mod;
        ll c = x * get_inv(y, mod) % mod;
        ll tmp = t * (bin(t, n, mod) - 1) % mod * get_inv(t - 1, mod) % mod;
        if (t == 1) tmp = n % mod;
        tmp = tmp * c % mod;
        if (r & 1)
            ans -= tmp;
        else
            ans += tmp;
        ans %= mod;
    }
    // ll m = get_inv(383008016,mod);
    ans = ans * bin(zhuangba, k, mod) % mod;
    ans = (ans + mod) % mod;
    return ans;
}
int32_t main() {
    // freopen("fibonacci-sum.in", "r", stdin);
    // freopen("out.txt","w",stdout);
    // int nol_cl = clock();
    // close;
    INIT();
    // cout << fac[10] << endl;
    int pp;
    cin >> pp;
    while (pp--) {
        // cc=1;
        cin >> n >> cc >> k;
        cout << solve(n, k) << endl;
    }

    //   printf("Time: %dms\n", int32_t ((clock()
    //   -nol_cl) / (long double)CLOCKS_PER_SEC * 1000));
    //   cout << endl;
    return 0;
}