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
constexpr int maxn = 3e5 + 10;
constexpr int M = 3e5 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
int n, lg[M], dep[M];
ll w[M], st[M][22], st1[M][22][2][2], dp1[2], dp2[2];
struct node {
    int v;
    ll w1, w2;
    node(int a, ll b, ll c) { v = a, w1 = b, w2 = c; }
    /* data */
};
vector<node> vec[M];
void dfs1(int u, int fa) {
    ll w1, w2;
    st[u][0] = fa, dep[u] = dep[fa] + 1;
    for (auto it : vec[u]) {
        int v = it.v;
        if (v == fa) continue;
        w1 = it.w1, w2 = it.w2;
        dfs1(v, u);
        umin(w[u], w[v] + w1 + w2);
    }
}
void dfs2(int u, int fa) {
    ll w1, w2;
    for (auto it : vec[u]) {
        int v = it.v;
        if (v == fa) continue;
        w1 = it.w1, w2 = it.w2;
        umin(w[v], w[u] + w1 + w2);
        dfs2(v, u);
    }
}
void dfs(int u, int fa) {
    ll w1, w2;
    for (auto it : vec[u]) {
        int v = it.v;
        if (v == fa) continue;
        w1 = it.w1, w2 = it.w2;
        dfs(v, u);
        st1[v][0][0][0] = min(w1, w[v] + w[u] + w2);
        st1[v][0][1][1] = min(w2, w[v] + w[u] + w1);
        st1[v][0][0][1] = min(w2 + w[v], w1 + w[u]);
        st1[v][0][1][0] = min(w2 + w[u], w[v] + w1);
    }
}
ll LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = lg[n]; i >= 0; i--) {
        if (dep[st[u][i]] >= dep[v]) u = st[u][i];
    }
    if (u == v) return u;
    for (int i = lg[n]; i >= 0; i--)
        if (st[u][i] != st[v][i]) u = st[u][i], v = st[v][i];
    return st[u][0];
}
LL Solve(int x, int y) {
    int u = ((x + 1) >> 1), v = ((y + 1) >> 1), lcap;
    if (dep[u] < dep[v]) {
        swap(u, v);
        swap(x, y);
    }
    lcap = LCA(u, v);
    LL tp0, tp1;
    dp1[(x + 1) & 1] = 0;
    dp1[((x + 1) & 1) ^ 1] = w[u];
    for (int i = lg[n]; i >= 0; i--) {
        if (dep[st[u][i]] >= dep[lcap]) {
            tp0 = dp1[0];
            tp1 = dp1[1];
            dp1[0] = min(tp0 + st1[u][i][0][0], tp1 + st1[u][i][1][0]);
            dp1[1] = min(tp0 + st1[u][i][0][1], tp1 + st1[u][i][1][1]);
            u = st[u][i];
        }
    }
    u = v;
    dp2[(y + 1) & 1] = 0;
    dp2[((y + 1) & 1) ^ 1] = w[u];
    for (int i = lg[n]; i >= 0; i--) {
        if (dep[st[u][i]] >= dep[lcap]) {
            tp0 = dp2[0], tp1 = dp2[1];
            dp2[0] = min(tp0 + st1[u][i][0][0], tp1 + st1[u][i][1][0]);
            dp2[1] = min(tp0 + st1[u][i][0][1], tp1 + st1[u][i][1][1]);
            u = st[u][i];
        }
    }
    return min(dp1[0] + dp2[0], dp1[1] + dp2[1]);
}
int main() {
    close;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    ll w1, w2;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v >> w1 >> w2;
        vec[u].push_back((node){v, w1, w2});
        vec[v].push_back((node){u, w1, w2});
    }
    memset(st1, 0x3f, sizeof st1);
    dfs1(1, 0);
    dfs2(1, 0);
    dfs(1, 0);
    for (int j = 1; j <= lg[n]; j++) {
        for (int u = 1; u <= n; u++) {
            st[u][j] = st[st[u][j - 1]][j - 1];
            st[u][j] = st[st[u][j - 1]][j - 1];
            st1[u][j][0][0] =
                min(st1[u][j - 1][0][0] + st1[st[u][j - 1]][j - 1][0][0],
                    st1[u][j - 1][0][1] + st1[st[u][j - 1]][j - 1][1][0]);
            st1[u][j][0][1] =
                min(st1[u][j - 1][0][0] + st1[st[u][j - 1]][j - 1][0][1],
                    st1[u][j - 1][0][1] + st1[st[u][j - 1]][j - 1][1][1]);
            st1[u][j][1][0] =
                min(st1[u][j - 1][1][0] + st1[st[u][j - 1]][j - 1][0][0],
                    st1[u][j - 1][1][1] + st1[st[u][j - 1]][j - 1][1][0]);
            st1[u][j][1][1] =
                min(st1[u][j - 1][1][0] + st1[st[u][j - 1]][j - 1][0][1],
                    st1[u][j - 1][1][1] + st1[st[u][j - 1]][j - 1][1][1]);
        }
    }
    CASET {
        int zz, zb;
        cin >> zz >> zb;
        cout << Solve(zz, zb) << endl;
    }
    return 0;
}