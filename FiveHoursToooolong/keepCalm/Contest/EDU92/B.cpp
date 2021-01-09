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
// template <class T>
// inline void add(T &x, T y) {
//     x += y;
//     if (x >= mod) x -= mod;
// }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260817, P_2 = 999998639;
int a[maxn], sum[maxn], n, k, z, add, ans;
void up() {
    cin >> n >> k >> z;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    ans = a[1];
    int pp = min(k + 1, n);
    for (int i = 2; i <= pp; i++) {
        int cnt = min((k - (i - 1) + 1) / 2, z);
        if (cnt <= 0) {
            ans = max(ans, sum[i]);
            continue;
        }
        add = sum[i] + cnt * a[i - 1] + a[i] * (cnt - 1);
        add += sum[i - 1 + k - (i - 1) - (cnt * 2 - 1)] - sum[i - 1];
        umax(ans, add);
    }
    cout << ans << endl;
}
void upp() {
    cin >> n >> k >> z;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            sum[i] = sum[i - 1] + a[i];
        }else {
            sum[i] = a[i];
        }
    }
    ans = sum[k];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= z && j <= k - i; j++) {
            // sum为前缀和
            // k-i 为 移动到i这个位置时，还剩下的移动次数
            // 如果剩余的移动次数够来回移动j次。 i->i-1 ,i-1>i
            // 这样算完整的一次来回移动
            if (j * 2 <= k - i)
                // sum[i + k - 2 * j - i]  i表示当前的位置 k-2*j-i
                // 表示到达当前位置 i并且来回移动j次后剩余的移动次数。所以i + k
                // - 2 * j - i表示最后可以达到的位置的前缀和
                ans = max(ans, (a[i] + a[i - 1]) * j + sum[i + k - 2 * j - i]);
            // 如果不够来回移动j次。 既最后一次向左移动后，不能回到i这个位置。
            else if (j * 2 - 1 <= k - i)
                ans = max(ans, (a[i] + a[i - 1]) * (j - 1) + a[i - 1] + sum[i]);
        }
    }
    cout << ans << endl;
}
int main() {
    close;
    CASET { upp(); }

    return 0;
}