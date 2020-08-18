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
//#include <ext/eb_ds/assoc_container.hpp>
//#include <ext/eb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define int long long
#define eps 1e-8
#define fi first
#define se second
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
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int mod = 1e9 + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
void umax(int &a, int b) {
    if (a < b) a = b;
}
void umin(int &a, int b) {
    if (a > b) a = b;
}
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
const int N = 3e5 + 10;
struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot;
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}

// int dis[N], si[N], n, k, vis[N];
// void dfs(int u, int fa) {
//     dis[u] = dis[fa] + 1;
//     si[u] = 1;
//     for (int i = head[u]; i; i = edge[i].nxt) {
//         int v = edge[i].to;
//         if (v == fa) continue;
//         dfs(v, u);
//         si[u] += si[v];
//     }
// }
int n, one, two, u, v, ans, aa, bb, cc;
int zz[maxn], fl[maxn], nxt[maxn][3], cnt[maxn], a[maxn], b[maxn], c[maxn];
vi g[maxn];
void dfs(int u, int fa) {
    if (fl[u] < 2) nxt[u][fl[u]]++;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        a[v] = min(a[v], a[u]);
        dfs(v, u);
        nxt[u][0] += nxt[v][0], nxt[u][1] += nxt[v][1];
    }
    cnt[u] = min(nxt[u][0], nxt[u][1]);
    zz[u] = cnt[u];
    nxt[u][0] -= cnt[u], nxt[u][1] -= cnt[u];
}
void up() {
    close;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        one += b[i], two += c[i];
        if (b[i] == c[i])
            fl[i] = 2, aa++;
        else if (!b[i] && c[i])
            fl[i] = 0, bb++;
        else if (b[i] && !c[i])
            fl[i] = 1, cc++;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    if (one != two) {
        cout << -1 << endl;
        return;
    }
    dfs(1, 0);
    // cout << aa << " ," << bb << " " << cc << endl;
    for (int i = 1; i <= n; i++) ans += 2 * cnt[i] * a[i];
    cout << ans << endl;
}
int32_t main() { up(); }