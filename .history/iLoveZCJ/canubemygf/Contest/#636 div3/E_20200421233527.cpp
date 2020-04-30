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
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}

int dis[N], si[N], n, k, vis[N], d[N], p[N];
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
queue<int> Q;
void bfs(int u) {
    while (!Q.empty()) Q.pop();
    Q.push(u);
    vis[u] = 1;
    d[u] = 0;
    p[u] = -1;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = edge[i].nxt) {
            if (!vis[edge[i].to]) {
                Q.push(edge[i].to);
                vis[edge[i].to] = 1;
                d[e[i].t] = d[u] + 1;
                p[e[i].t] = u;
            }
        }
    }
}
void restore(int x) {
    vector<int> res;
    for (int v = x; v != -1; v = p[v]) {
        res.push_back(v);
    }
    std::reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) printf("%d", res[i]);
    puts("");
}
int main() {
    close;
    CASET {}
}