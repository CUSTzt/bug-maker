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
#define int long long 
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
const int N = 1e6 + 10;
struct Edge {
    int nxt, to, w;
} edge[N<<1];
int head[N], tot;
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}

int ans, ans2, ans3, anss;
int n, v[maxn], cnt, v2[maxn], dp[maxn], d[maxn], s[maxn], r[maxn], st;
bool dfs(int u, int fa) {
    if (v[u] == 1) {
        v[u] = 2;
        r[++cnt] = u, v2[u] = 1;
        return 1;
    }  //找到邻接点
    v[u] = 1;
    for (int i = head[u]; i; i = edge[i].nxt) {
        if (i != (((fa - 1) ^ 1) + 1) && dfs(edge[i].to, i)) {  //如果当前边不是上一条边并且当前节点在环上
            if (v[u] != 2) {  //不是邻接点
                r[++cnt] = u, v2[u] = 1, s[cnt] = s[cnt - 1] + edge[i].w;
            } else {
                s[st - 1] = s[st] - edge[i].w;
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

void DP(int u) {
    v2[u] = 1;
    for (int i = head[u]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        if (v2[y]) continue;
        DP(y);
        ans = max(ans, d[u] + d[y] + edge[i].w);
        d[u] = max(d[u], d[y] + edge[i].w);
    }
}
ll work(int root) {
    st = cnt + 1, ans2 = 0, ans3 = 0;
    dfs(root, 0);
    for (int i = st; i <= cnt; i++) {
        ans = 0;
        DP(r[i]);
        ans2 = max(ans2, ans);
        dp[i + cnt - st + 1] = dp[i] = d[r[i]];
        s[i + cnt - st + 1] = s[i + cnt - st] + s[i] - s[i - 1];
    }
    deque<int> q;
    for (int i = st; i <= 2 * cnt - st + 1; i++) {
        while (!q.empty() && q.front() <= i - cnt + st - 1) {
            q.pop_front();
        }
        if (!q.empty()) {
            ans3 = max(ans3, dp[i] + dp[q.front()] + s[i] - s[q.front()]);
        }
        while (q.size() && dp[q.back()] - s[q.back()] <= dp[i] - s[i])
            q.pop_back();
        q.push_back(i);
    }
    // cout << "root ===  " << root << "   max === " << max(ans2, ans3) << '\n';
    return max(ans3,ans2);
}
int32_t main() {
    close;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        add_edge(v, i, w);
        add_edge(i, v, w);
    }
    for(int i = 1; i <= n; i++){
        if(!v2[i]){
            anss+=work(i);
        }
    }
    cout << anss << endl;
}
