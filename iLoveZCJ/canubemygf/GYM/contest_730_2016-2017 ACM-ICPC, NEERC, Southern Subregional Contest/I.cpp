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
constexpr int maxn = 3333 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
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
struct node {
    int x, y, id;
    /* data */
} a[maxn];
int cmp(node a, node b) { return a.y > b.y; }
int dp[maxn][maxn], vis[maxn], n, p, s;
pii pre[maxn][maxn];
void dfs(int x, int y) {
    if (!x) return;
    if (pre[x][y].se == 1) vis[x] = 1;
    dfs(x - 1, pre[x][y].fi);
}
int main() {
    close;
    cin >> n >> p >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
    }
    for (int j = 1; j <= n; j++) {
        cin >> a[j].y;
        a[j].id = j;
    }
    memset(dp, 0xcf, sizeof dp);
    sort(a + 1, a + 1 + n, cmp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, p); j++) {
            if (i - j <= s && dp[i - 1][j] + a[i].y > dp[i][j])
                dp[i][j] = dp[i - 1][j] + a[i].y, pre[i][j] = {j, 2};
            if (i - j > s && dp[i - 1][j] > dp[i][j])
                dp[i][j] = dp[i - 1][j], pre[i][j] = {j, 0};
            if (j - 1 >= 0 && dp[i - 1][j - 1] + a[i].x > dp[i][j])
                dp[i][j] = dp[i - 1][j - 1] + a[i].x, pre[i][j] = {j - 1, 1};
        }
    }
    cout << dp[n][p] << endl;
    dfs(n , p);
    int cn = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]) cout << a[i].id << ' ';
    }cout << endl;
    for(int i = 1; i <= n; i++){
        if(!vis[i] && cn < s) cout << a[i].id << ' ', cn++;
        // cout << endl;
    }cout << endl;
}