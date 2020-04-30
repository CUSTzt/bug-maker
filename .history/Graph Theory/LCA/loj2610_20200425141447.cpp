// @DateTime:    2020-04-25 14:07:16
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
int n, m, dep[maxn], f[maxn][21];
struct node {
    int x, y, dis;
} edge1[N << 1];
struct Edge {
    int nxt, to, w;
} edge2[N << 1];
int head[N], tot;
void add_edge(int u, int v, int w) {
    edge2[++tot].nxt = head[u];
    edge2[tot].to = v;
    edge2[tot].w = w;
    head[u] = tot;
}
int cmp(node &a, node &b) { return a.dis > b.dis; }
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
void kruskal() {
    sort(edge1 + 1, edge1 + 1 + m);
    init(maxn);
    for (int i = 1; i <= m; i++) {
        int x = edge1[i].x, y = edge1[i].y;
        if(x != y){
            fa[x] = y;
            add_edge(edge1[i].x, edge1[i].y,edge1[i].dis);
            add_edge(edge1[i].y, edge1[i].x,edge1[i].dis);
        }
    }
}
void dfs(int u , int fa){
    for(int i = head[u]; i ; i = edge2[i].nxt){
        int to = edge2[i].to;
        if(fa == to)continue;
        
    }
}
int main() {}