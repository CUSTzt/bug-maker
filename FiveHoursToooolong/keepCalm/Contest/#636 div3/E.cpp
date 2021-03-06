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
#define int long long 
#define fi first
#define se second
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
void add_edge(int u, int v) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    // edge[tot].w = w;
    head[u] = tot;
}

int dis[3][N], si[N], n, m, k, vis[N], a, b, c, p[maxn];
void bfs(int s, int dis[]) {
    queue<int> que;
    que.push(s);
    dis[s] = 1;
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int i = head[node]; i; i = edge[i].nxt) {
            int to = edge[i].to;
            if (!dis[to]) {
                dis[to] = dis[node] + 1;
                que.push(to);
            }
        }
    }
}
void slove() {
    cin >> n >> m >> a >> b >> c;
    for (int i = 0; i < n + 10; i++) {
        head[i] = 0;
        for (int j = 0; j < 3; j++) dis[j][i] = 0;
    }
    tot = 0;
    for (int i = 1; i <= m; i++) cin >> p[i];
    sort(p + 1, p + 1 + m);
    for (int i = 1; i <= m; i++) {
        p[i] += p[i - 1];
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    bfs(a, dis[0]);
    bfs(b, dis[1]);
    bfs(c, dis[2]);
    ll ans = linf;
    for (int i = 1; i <= n; i++) {
        if (dis[0][i] + dis[1][i] + dis[2][i] - 3 > m) continue;
        ans = min(ans, p[dis[1][i] - 1] + p[dis[0][i] - 1 + dis[1][i] - 1 + dis[2][i] - 1]);
    }
    cout << ans << endl;
}
int32_t main() {
    close;
    CASET { slove(); }
}