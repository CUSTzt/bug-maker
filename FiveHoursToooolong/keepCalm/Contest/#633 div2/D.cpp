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
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int father[maxn], deg[maxn], dis[maxn];
int Find(int x)  //并查集查找父节点
{
    if (father[x] == x) return father[x];
    return father[x] = Find(father[x]);
}
void Union(int x, int y)  //合并
{
    int fa = Find(x);
    int fb = Find(y);
    if (fa != fb) father[fb] = fa;
}
pii e[maxn];
vector<pii> G[maxn];
int n;
void dfs(int u, int fa) {
    dis[u] = 1 ^ dis[fa] ;
    for (auto s : G[u])
        if (s.first != fa) dfs(s.first, u);
}
int mx, mn;
void solve() {
    cin >> n;
    vector<int> a(n + 10), b(n + 10);
    for (int i = 1; i < n; i++) {
        cin >> a[i] >> b[i];
        e[i] = make_pair(a[i], b[i]);
        G[a[i]].eb(make_pair(b[i], i));
        G[b[i]].eb(make_pair(a[i], i));
        deg[a[i]]++;
        deg[b[i]]++;
    }
    dfs(1, 0);
    vector<int> vv(10, 0);
    for (int i = 0; i < n + 5; i++) {
        father[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            vv[dis[i]] = 1;
        }
    }
    if (vv[0] && vv[1]) {
        mn = 2;
    } else
        mn = 0;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        vec.clear();
        for (auto it : G[i]) {
            if (deg[it.first] == 1) {
                vec.eb(it.second);
            }
        }
        if (vec.size() > 1) {
            int pq = vec[0];
            for (auto it : vec) Union(pq, it);
        }
    }
    for (int i = 0; i < n; i++) {
        if (father[i] == i) mx++;
    }
    cout << mn+1 << ' ' << mx - 1 << endl;
}
int main() { solve(); }