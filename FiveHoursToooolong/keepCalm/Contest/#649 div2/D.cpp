//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
//target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
// template <class T>
// inline void umin(T &x, T y) {
//     x = x > y ? y : x;
// }
// template <class T>
// inline void umax(T &x, T y) {
//     x = x < y ? y : x;
// }
// template <class T>
// inline void add(T &x, T y) {
//     x += y;
//     if (x >= mod) x -= mod;
// }
// template <class T>
// inline void dec(T &x, T y) {
//     x -= y;
//     if (x < 0) x += mod;
// }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
int d[maxn], vis[maxn], need, n, m, k, x, y;
vi v[maxn], ans;
void dfs(int x, int fa) {
    ans.push_back(x);
    d[x] = ans.size();  // x在ans中的位置
    for (auto i : v[x]) {
        if (i == fa) continue;
        if (!d[i])  //如果没有遍历过，往下遍历
            dfs(i, x);
        else if (d[x] - d[i] + 1 <= k &&
                 d[x] - d[i] + 1 >=
                     0)  //如果已经遍历过，说明是个环，判断环的大小
        {
            printf("2\n%d\n",
                   d[x] - d[i] + 1);  //环的大小 通过在ans中的编号搞出来
            for (
                int j = d[i] - 1; j < d[x];
                j++)  //输出环，因为在vector种下标的缘故，整体要往左移动一个单位
                printf("%d ", ans[j]);
            printf("\n");
            exit(0);
        }
    }
    //如果x没有遍历过  记得把和x相邻的 都标记，为了第一种答案
    if (!vis[x])
        for (auto i : v[x]) vis[i] = 1;
    //相当于反向回溯，因为他要的独立集，是不相邻的，处理最后一个元素时，把和她相邻的都标记，然后把最后一个删掉，删掉的记作x，然后再往回
    //如果此时最后的 和 x
    //相邻，那么已经被标记过，也就不能再执行上面的语句了，就直接被删掉
    //这样不会出现重复被标记的问题
    ans.pop_back();
}
int main() {
    cin >> n >> m >> k;
    need = (k + 1) / 2;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        v[x].eb(y), v[y].eb(x);
    }
    dfs(1, 0);
    cout << 1 << endl;
    for (int i = 1; i <= n && need; i++)
        if (!vis[i]) printf("%d ", i), need--;
}