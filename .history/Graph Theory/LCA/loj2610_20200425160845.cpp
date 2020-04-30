// @DateTime:    2020-04-25 16:08:38
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
//target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
struct Edge1 {
    int x, y, dis;
} edge1[50005];  //题目所给的图
struct Edge2 {
    int to, next, w;
} edge2[100005];  //最大生成树的图
int cnt, n, m, head[MAXN], deep[MAXN], f[MAXN], fa[MAXN][21], w[MAXN][21];
// f数组表示并查集中的父节点，fa数组表示树上的父节点，w数组表示最大载重
bool vis[MAXN];

void addedge(int from, int to, int w) {  //前向星存图
    edge2[++cnt].next = head[from];
    edge2[cnt].to = to;
    edge2[cnt].w = w;
    head[from] = cnt;
    return;
}

bool CMP(Edge1 x, Edge1 y) {
    return x.dis > y.dis;  //将边权从大到小排序
}

int find(int x) {  //并查集寻找父节点
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void kruskal() {
    sort(edge1 + 1, edge1 + m + 1, CMP);
    for (int i = 1; i <= n; i++) f[i] = i;  //并查集初始化
    for (int i = 1; i <= m; i++)
        if (find(edge1[i].x) != find(edge1[i].y)) {
            f[find(edge1[i].x)] = find(edge1[i].y);
            addedge(edge1[i].x, edge1[i].y, edge1[i].dis);
            addedge(edge1[i].y, edge1[i].x, edge1[i].dis);  //无向图，双向加边
        }
    return;
}

void dfs(int node) {
    vis[node] = true;
    for (int i = head[node]; i; i = edge2[i].next) {  //前向星遍历
        int to = edge2[i].to;
        if (vis[to]) continue;
        deep[to] = deep[node] + 1;  //计算深度
        fa[to][0] = node;           //储存父节点
        w[to][0] = edge2[i].w;      //储存到父节点的权值
        dfs(to);
    }
    return;
}

int lca(int x, int y) {
    if (find(x) != find(y)) return -1;  //不连通，输出-1
    int ans = INF;
    if (deep[x] > deep[y]) swap(x, y);  //保证y节点更深
    //将y节点上提到于x节点相同深度
    for (int i = 20; i >= 0; i--)
        if (deep[fa[y][i]] >= deep[x]) {
            ans = min(ans, w[y][i]);  //更新最大载重（最小边权）
            y = fa[y][i];             //修改y位置
        }
    if (x == y) return ans;  //如果位置已经相等，直接返回答案
    //寻找公共祖先
    for (int i = 20; i >= 0; i--)
        if (fa[x][i] != fa[y][i]) {
            ans = min(ans, min(w[x][i], w[y][i]));  //更新最大载重（最小边权）
            x = fa[x][i];
            y = fa[y][i];  //修改x,y位置
        }
    ans = min(ans, min(w[x][0], w[y][0]));
    //更新此时x,y到公共祖先最大载重，fa[x][0], fa[y][0]即为公共祖先
    return ans;
}

int main() {
    int x, y, z, q;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        edge1[i].x = x;
        edge1[i].y = y;
        edge1[i].dis = z;
    }  //储存题目所给图
    kruskal();
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {  // dfs收集信息
            deep[i] = 1;
            dfs(i);
            fa[i][0] = i;
            w[i][0] = INF;
        }
    // LCA初始化
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            w[j][i] = min(w[j][i - 1], w[fa[j][i - 1]][i - 1]);
        }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));  //回答询问
    }
    return 0;
}