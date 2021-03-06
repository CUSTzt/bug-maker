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
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define int long long
#define eb emplace_back
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
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
struct Edge {
    int nxt, to;
    ll w, zz;
} edge[maxn];
int head[maxn], tot;
void add_e(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].zz = tot;
    edge[tot].w = w;
    head[u] = tot;
}

int dis[maxn], si[maxn], n, k, vis[maxn], u, v;
void dfs(int u, int fa) {
    si[u] = 1;
    dis[u] = dis[fa] + 1;
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        si[u] += si[v];
    }
}
int pp[maxn];
int cmp(int x, int y) {
    int aa = dis[x] - si[x], bb = dis[y] - si[y];
    return aa > bb;
}
int ans = 0;
void init() {
    for (int i = 1; i <= n + 10; i++) {
        pp[i] = i;
    }
    ans = 0;
    sort(pp + 1, pp + 1 + n, cmp);
    for (int i = k; i >= 1; i--) {
        ans += dis[pp[i]] - si[pp[i]];
    }
    // cout << 1 << endl;
    cout << ans << endl;
}
void slove() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        add_e(v, u, 1);
        add_e(u, v, 1);
    }
    dfs(1, 0);
    init();
}
int32_t main() { slove(); }