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
#define int long long
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
void up() {
    int n;
    cin >> n;
    vi a(n+10), cf(n+10), odd(n+10), even(n+10), mn(10, -1);
    int oo = 0, ev = 0, fu = 0, ans = 0 , sum = 0;
    mn[0] = 0, mn[1] = 1e18; 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) {
            fu -= a[i];
            oo += a[i];
            odd[i] = oo;
            if (i > 0) even[i] = even[i - 1];
        } else {
            fu += a[i];
            ev += a[i];
            even[i] = ev;
            if (i > 0) odd[i] = odd[i - 1];
        }
        // cout << 0 << endl;
        umin(mn[i & 1], fu);
        umax(ans, fu - mn[i & 1]);
        if (i & 1) sum += a[i];
        // cout << "sum == " << sum << "  ans == " << ans << endl;
    }
    cout << sum + ans << endl;
    // cf[0] = a[0];
    // sum[0] = sum[0];
    // for(int i = 1; i < n; i++){
    //     cf[i] = a[i] - a[i-1];
    //     sum[i] = sum[i-1] + cf[i];
    // }
    // if (odd[n - 1] > even[n - 1]) {
    //     int tp = 0;
    //     for (int i = 0; i < n; i++) umax(tp, odd[i] - even[i]);
    //     cout << odd[n - 1] + tp << endl;
    // } else if (odd[n - 1] < even[n - 1]) {
    //     int tp = 0;
    //     for (int i = 0; i < n; i++) umax(tp, -odd[i] + even[i]);
    //     cout << even[n - 1] + tp << endl;
    // } else {
    //     int tp = 0;
    //     for (int i = 0; i < n; i++) umax(tp, abs(-odd[i] + even[i]));
    //     cout << odd[n - 1] + tp << endl;
    // }
    // for (int i = 0; i < n; i++) cout << even[i] << " \n"[i == n - 1];
    // for (int i = 0; i < n; i++) cout << odd[i] << " \n"[i == n - 1];
}
int32_t main() {
    // close;
    CASET { up(); }
}