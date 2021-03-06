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
int n, q, a[maxn], dep[maxn], f[maxn][20], to[maxn];
vi v[maxn];
void dfs(int u, int fa) {
    int x = fa;
    for (int k = 19; k >= 0; k--)
        if (f[x][k] && a[f[x][k]] <= a[u])
            x = f[x][k];  //如果x往上跳2^k步这个点存在，且这个点的权值比a[p]要小，就跳到这个点再往上跳
    if (a[x] > a[u])
        f[u][0] = x;  //判断比a[p]大的点到底是x还是x的上面那个点
    else
        f[u][0] = f[x][0];  //向上倍增的找到第一个比p权值大的点

    for (int i = 1; i < 20; i++) {  //倍增的求出每个点向上2^j步的点
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    dep[u] = dep[fa] + 1;

    for (auto it : v[u]) {
        // cout << it << endl;
        if (fa != it) {
            dfs(it, u);
        }
    }
}
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    for(int i = n+1; i <= n+q; i++){
        int x, y , c;
        cin >> x >> y >> c;
        v[i].eb(x),v[x].eb(i);
        a[i] = c;
        to[i-n] = y;
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++)
    {
        int ans = 0;
        int x = i + n;   //i+n是第i个询问的起点
        for (int k = 19; k >= 0; k--)   //k从大到小枚举
            if (dep[f[x][k]] >= dep[to[i]])   //如果跳完之后深度小于目标点深度就已经走过了，跳跃高度要减小
            {
                ans += (1 << k);           //点数加2^k
                x = f[x][k];               //向上跳2^k个点
            }
        printf("%d\n", ans);
    }

}