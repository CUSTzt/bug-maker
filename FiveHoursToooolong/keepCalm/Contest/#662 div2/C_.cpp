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
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
// int a[maxn], x;
int main() {
    close;
    CASET {
        int n, x, mx = 0, c = 0;
        cin >> n;
        vi cnt(n + 10);
        for (int i = 1; i <= n; i++) {
            cin >> x;
            cnt[x]++;
        }
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == mx) {
                c++;
            } else if (cnt[i] > mx) {
                mx = cnt[i], c = 1;
            }
        }
        // https://blog.csdn.net/StandNotAlone/article/details/107873256
        cout << c + (n - mx * c) / (mx - 1) - 1 << endl;
    }

    return 0;
}

/*

我们先通过桶排序找到这些数中出现次数最多为多少次，记为Max，这个样例中Max=3。
出现次数为3的数字分别为1,2,3这三种。

在不考虑其他数字的情况下，我们采用顺序间隔摆放:1,2,3…1,2,3…1,2,3
这样的构造方式使得值相等的数字之间的距离尽可能大，距离值为Max-1=2。

注意到上面的构造中有用省略号“…”表示的空区，这个空区是我们用来摆放剩余数字的。注意到这个空区的个数为Max-1，而剩下的其他数字的出现次数最多也不会等于Max，也就是最多只能和空区的数量相同，等于Max-1，比如对于数字4出现了两次，我们继续平均摆放4到这些空区中就是了。

最终的答案为Max-1再加上每个空区中摆放的数字个数中最小的那个，因此我们要使得这些空区中的数字个数最小的那个值尽可能大，因此我们采用平均摆放的方式。

摆放4后效果为1,2,3,4…1,2,3,4…1,2,3。最终效果为1,2,3, 4,6,8 1,2,3, 4,7, 1,2,3。

记出现次数等于Max的数字个数为cas，那么除了这些数字外的数的个数等于n-Max××cas，空区的个数为Max-1。
不考虑空区的情况下，值相等的数字之间的距离为Max-1，增加空区后，答案增加的值为（n-Max××cas）/（Max-1）。
最终答案就是Max-1+（n-Max××cas）/（Max-1）。*/