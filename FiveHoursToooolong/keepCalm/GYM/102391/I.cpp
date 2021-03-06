//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
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
#define SZ(a) int32_t(a.size())
#define ALL(x) (x).begin(), (x).end()
#define trav(a, x) for (auto &a : x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define int LL
#define close                                                              \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), \
        cout << fixed << setprecision(10)
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
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll ret = ex_gcd(b, a % b, y, x);
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
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
constexpr int maxn =
    500 + 10;  // remember to calculate. if tle, check maxn first.
ll n, m, u, v, z;
ll d[maxn][maxn], w[maxn][maxn], vis[maxn], rk[maxn][maxn], frm[maxn],
    ansx[maxn], ansy[maxn], dis[maxn], s1, s2, tot, ans;
vi e[maxn];
int32_t main() {
    close;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = w[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) d[i][i] = w[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> z;
        z *= 2;
        d[u][v] = d[v][u] = w[u][v] = w[v][u] = z;
        e[u].eb(v), e[v].eb(u);
    }

    auto findct = [&]() {
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) rk[i][j] = j;
            for (int j = 1; j <= n; j++)
                for (int k = j + 1; k <= n; k++)
                    if (d[i][rk[i][j]] > d[i][rk[i][k]])
                        swap(rk[i][j], rk[i][k]);
        };
        ll mi = INF;
        for (int u = 1; u <= n; u++)
            for (int v : e[u]) {
                if (u > v) continue;
                if ((d[u][rk[u][n]] * 2) < mi) {
                    dis[s1] = dis[s2] = INF;
                    mi = d[u][rk[u][n]] * 2, s1 = s2 = u, dis[u] = 0;
                }
                if ((d[v][rk[v][n]] * 2) < mi) {
                    dis[s1] = dis[s2] = INF;
                    mi = d[v][rk[v][n]] * 2, s1 = s2 = v, dis[v] = 0;
                }
                for (int last = n, i = n - 1; i; i--)
                    if (d[v][rk[u][i]] > d[v][rk[u][last]]) {
                        ll tmp = d[u][rk[u][i]] + d[v][rk[u][last]] + w[u][v];
                        if (tmp < mi) {
                            dis[s1] = dis[s2] = INF;
                            mi = tmp;
                            s1 = u, s2 = v;
                            dis[s1] = tmp / 2 - d[u][rk[u][i]];
                            dis[s2] = w[u][v] - dis[s1];
                        }
                        last = i;
                    }
            }
        return mi / 2;
    };

    priority_queue<pii, vector<pii>, greater<pii> > q;
    for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = false;
    ans = findct();
    if (s1 != s2)
        q.push({dis[s1], s1}), q.push({dis[s2], s2});
    else
        q.push({dis[s1], s1});
    tot = 0;
    if (s1 != s2) ++tot, ansx[1] = s1, ansy[1] = s2;
    int u;
    pii d;
    while (q.size()) {
        d = q.top();
        q.pop();
        u = d.second;
        if (d.first != dis[u] || vis[u]) continue;
        vis[u] = true;
        if (u != s1 && u != s2) ++tot, ansx[tot] = frm[u], ansy[tot] = u;
        for (int v : e[u]) {
            if (dis[v] <= dis[u] + w[u][v]) continue;
            dis[v] = dis[u] + w[u][v];
            frm[v] = u;
            q.push({dis[v], v});
        }
    }
    cout << ans << endl;
    for (int i = 1; i < n; i++) {
        cout << ansx[i] << " " << ansy[i] << endl;
    }
    return 0;
}