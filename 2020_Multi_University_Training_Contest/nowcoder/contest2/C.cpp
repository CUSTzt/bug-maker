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
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
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
void print(int a, int b) {
    if (a > b) swap(a, b);
    cout << a << " " << b << endl;
}
int deg[maxn], fa[maxn], vis[maxn], ls[maxn], tot = 0;
vector<int> g[maxn];
int n , m, u , v;
void dfs(int x) {
    vis[x] = 1;
    if (deg[x] == 1) {
        ls[++tot] = x;
        return;
    }
    for (int i = 0; i < g[x].size(); i++) {
        int to = g[x][i];
        if (vis[to] == 1) continue;
        dfs(to);
    }
    return;
}
int main() {
    close;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        deg[u]++,deg[v]++;
        g[u].push_back(v),g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 1) {
            dfs(i);
            break;
        }
    }
    memset(vis, 0, sizeof(vis));
    m = (tot + 1) / 2;
    cout << m << endl;
    for (int i = 1, j = m + 1; i <= tot / 2; i++, j += 3) {
        if (j > tot) {
            j = m + 1;
            while (vis[j] == 1) {
                j++;
            }
        }
        vis[i] = vis[j] = 1;
        print(ls[i], ls[j]);
    }
    if (tot & 1) print(ls[1], ls[m]);
}
