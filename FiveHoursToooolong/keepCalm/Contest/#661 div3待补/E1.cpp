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
#define int LL
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
int tot = 0, u, v, w, n, S;
vector<pii> e[maxn];
vi siz(maxn), weight(maxn);
void dfs(int u, int fa) {
    // cout << "u == " << u << endl;
    if (fa != -1 && e[u].size() == 1) {
        siz[u] = 1;
    }
    for (auto [v, w] : e[u]) {
        if (v == fa) continue;
        weight[v] = w;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
void up() {
    cin >> n >> S;
    // cout << "n == " << n << "   S==" << S << endl;
    for (int i = 0; i < n + 10; i++) e[i].clear();
    siz.clear();
    siz.resize(n, 0);
    weight.clear();
    weight.resize(n, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        --u, --v;
        e[u].eb(v, w), e[v].eb(u, w);
    }
    dfs(0, -1);
    // cout << "fuck" << endl;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        S -= 1ll * siz[i] * weight[i];
        // cout << siz[i] << "    " << weight[i] << endl;
    }
    // cout << "S == " << S << endl;
    priority_queue<pii> h;
    for (int i = 1; i < n; i++) {
        h.emplace(1ll * siz[i] * ((weight[i] + 1) / 2), i);
    }
    // cout << "fuck2" << endl;
    while (S < 0) {
        auto [w, u] = h.top();
        h.pop();
        // std::cout << "w === " << w << "  u == " << u << endl;
        ++cnt;
        S += w;
        weight[u] /= 2;
        h.emplace(1ll * siz[u] * ((weight[u] + 1) / 2), u);
    }
    // cout << "fuck3" << endl;
    cout << cnt << endl;
}
int32_t main() {
    // close;
    CASET { up(); }
    return 0;
}