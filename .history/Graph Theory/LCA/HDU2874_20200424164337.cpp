// @DateTime:    2020-04-24 16:28:06
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
#define eb emplace_back
#define SZ(a) int(a.size())
#define ALL(x) (x).begin(), (x).end()
#define trav(a, x) for (auto &a : x)
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
int fa[maxn];
void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = y;
}
int n, m, k, f[maxn][22], dep[maxn], dis[maxn];
int dfs(int x, int fa, int d) {
    f[x][0] = fa;
    dep[x] = dep[fa] + 1;
    dis[x] = d;
    for (int i = 1; i <= 19; i++) {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (int i = head[x]; i; i = edge[i].nxt) {
        int v = edge[i].nxt;
        if (v != fa) {
            dfs(v, x, dis[x] + edge[i].w);
        }
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (dep[f[b][i]] >= dep[a]) b = f[b][i];
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (f[a][i] != f[b][i]) {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}
int main() {
    close;
    while (cin >> n >> m >> k) {
        init(n + 10);
        tot = 0;
        for (int i = 0; i <= 10; i++) {
            head[i] = dep[i] = dis[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            add_edge(x, y, z);
            add_edge(y, x, z);
            Union(x, y);
        }
        for (int i = 0; i < k; i++) {
            int a ,  b ;
            cin >> a >> b;
            if(find(a) ! = find(b)){
                
            }
        }
    }
}