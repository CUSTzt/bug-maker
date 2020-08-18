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
#define trav(a, x) for (auto& a : x)
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
ll ex_gcd(ll a, ll b, ll& x, ll& y) {
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
inline void umin(T& x, T y) {
    x = x > y ? y : x;
}
template <class T>
inline void umax(T& x, T y) {
    x = x < y ? y : x;
}
template <class T>
inline void dec(T& x, T y) {
    x -= y;
    if (x < 0) x += mod;
}
template <class T>
inline void add(T& x, T y) {
    x += y;
    if (x >= mod) x -= mod;
}
const double PI = acos(-1.0);
constexpr int maxn = 55;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
int mp[maxn][maxn], ans, dis[maxn], last[maxn], vis[maxn], n, k, u , v, w;
struct node {
    int v, data;
    friend int operator<(node a, node b) { return a.data > b.data; }
} t, d;

void dijkstra(int s) {
    priority_queue<node> Q;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    memset(last, 0, sizeof(last));
    dis[s] = 0;
    t.v = s;
    t.data = 0;
    Q.push(t);
    while (!Q.empty()) {
        if (vis[Q.top().v] == 1) {
            Q.pop();
            continue;
        }
        t = Q.top();
        Q.pop();
        int u = t.v;
        dis[u] = t.data;
        vis[u] = 1;
        for (int i = 1; i <= n; i++) {
            if (mp[u][i] >= INF) continue;
            if (vis[i] == 0 && dis[i] > dis[u] + mp[u][i]) {
                dis[i] = dis[u] + mp[u][i];
                last[i] = u;
                d.v = i;
                d.data = dis[i];
                Q.push(d);
            }
        }
    }
}

void dfs(int pos) {
    dijkstra(1);
    if (pos == k) {
        ans = max(ans, dis[n]);
        return;
    }
    vector<int> a;
    a.clear();
    int x = n;
    a.push_back(x);
    while (last[x] != 0) {
        a.push_back(last[x]);
        x = last[x];
    }
    for (int i = 0; i < a.size() - 1; i++) {
        int u = a[i], v = a[i + 1];
        int tmp = mp[u][v];
        mp[u][v] = mp[v][u] = INF;
        dfs(pos + 1);
        mp[u][v] = mp[v][u] = tmp;
    }
}
void up() {
    cin >> n >> k;
    memset(mp , 0 ,sizeof mp);
    for (int i = 1; i <= (n - 1) * n / 2; i++) {
        cin >> u >> v >> w;
        mp[u][v] = w, mp[v][u] = w;
    }
    ans = 0;
    dfs(0);
    cout << ans << endl;
}

int main() {
    close;
    CASET { up(); }
    return 0;
}