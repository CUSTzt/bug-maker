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
struct Edge {
    int to, dis, cost;
} dege;
vector<Edge> e[maxn];
void addedge(int a, int b, int d, int p) {
    e[a].push_back({b, d, p});
    e[b].push_back({a, d, p});
}
int n, m, a, b, d, p, st, ed;
int dis[maxn], cost[maxn];
void solve() {
    for (int i = 1; i <= n + 10; i++) {
        e[i].clear();
        dis[i] = INF, cost[i] = INF;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> d >> p;
        addedge(a, b, d, p);
    }
    cin >> st >> ed;
    dis[st] = 0, cost[st] = 0;
    std::queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int fr = q.front();
        q.pop();
        for (auto it : e[fr]) {
            if (dis[fr] + it.dis < dis[it.to] || (dis[fr] + it.dis == dis[it.to] && cost[fr] + it.cost < cost[it.to])) {
                dis[it.to] = dis[fr] + it.dis;
                cost[it.to] = cost[fr] + it.cost;
                q.push(it.to);
            }
        }
    }
    cout << dis[ed] << ' ' << cost[ed] << endl;
}
int main() {
    close;
    while (cin >> n >> m && n + m) {
        solve();
    }
}