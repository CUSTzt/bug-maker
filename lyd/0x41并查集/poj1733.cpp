//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <bitset>
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
#define SZ(a) int32_t(a.size())
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
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
constexpr int maxn =
    1e6 + 10;  // remember to calculate. if tle, check maxn first.
namespace edge_with_value {
struct {
    int l, r, ans;
} query[10010];
int a[20010], fa[20010], d[20010], n, m, t;
void read_discrete() {  // 读入、离散化
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char str[5];
        scanf("%d%d%s", &query[i].l, &query[i].r, str);
        query[i].ans = (str[0] == 'o' ? 1 : 0);
        a[++t] = query[i].l - 1;
        a[++t] = query[i].r;
    }
    sort(a + 1, a + t + 1);
    n = unique(a + 1, a + t + 1) - a - 1;
}
int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    d[x] ^= d[fa[x]];
    return fa[x] = root;
}
void solve() {
    read_discrete();
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        // 求出l-1和r离散化之后的值
        int x = lower_bound(a + 1, a + n + 1, query[i].l - 1) - a;
        int y = lower_bound(a + 1, a + n + 1, query[i].r) - a;
        // 执行get函数，得到树根，并进行路径压缩
        int p = get(x), q = get(y);
        if (p == q) {                             // 已经在同一集合内
            if ((d[x] ^ d[y]) != query[i].ans) {  // 矛盾，输出
                cout << i - 1 << endl;
                return;
            }
        } else {  // 不在同一集合，合并
            fa[p] = q;
            d[p] = d[x] ^ d[y] ^ query[i].ans;
        }
    }
    cout << m << endl;  // 没有矛盾
}
}  // namespace edge_with_value
namespace extend_rang {
struct {
    int l, r, ans;
} query[10010];
int a[20010], fa[40010], n, m, t;
void read_discrete() {  // 读入、离散化
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char str[5];
        scanf("%d%d%s", &query[i].l, &query[i].r, str);
        query[i].ans = (str[0] == 'o' ? 1 : 0);
        a[++t] = query[i].l - 1;
        a[++t] = query[i].r;
    }
    sort(a + 1, a + t + 1);
    n = unique(a + 1, a + t + 1) - a - 1;
}
int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
void solve() {
    read_discrete();
    for (int i = 1; i <= 2 * n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        // 求出l-1和r离散化之后的值
        int x = lower_bound(a + 1, a + n + 1, query[i].l - 1) - a;
        int y = lower_bound(a + 1, a + n + 1, query[i].r) - a;
        int x_odd = x, x_even = x + n;
        int y_odd = y, y_even = y + n;
        if (query[i].ans == 0) {              // 回答奇偶性相同
            if (get(x_odd) == get(y_even)) {  // 与已知情况矛盾
                cout << i - 1 << endl;
                return;
            }
            fa[get(x_odd)] = get(y_odd);  // 合并
            fa[get(x_even)] = get(y_even);
        } else {                             // 回答奇偶性不同
            if (get(x_odd) == get(y_odd)) {  // 与已知情况矛盾
                cout << i - 1 << endl;
                return;
            }
            fa[get(x_odd)] = get(y_even);  // 合并
            fa[get(x_even)] = get(y_odd);
        }
    }
    cout << m << endl;  // 没有矛盾
}
}  // namespace extend_rang

int main() {
    edge_with_value::solve();
    //extend_rang::solve();
    return 0;
}