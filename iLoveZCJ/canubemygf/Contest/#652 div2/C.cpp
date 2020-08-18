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
#define int long long
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
int a[maxn], w[maxn];
int32_t main() {
    close;
    CASET {
        ll ans = 0;
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int f = 0;
        for (int i = 1; i <= k; i++) {
            cin >> w[i];
            if (w[i] == 1) {
                f++;
            }
        }
        sort(a + 1, a + n + 1);
        // sort(w + 1, w + k + 1, greater<int>());
        // // for(int i = 1; i <= k; i++){
        // //     cout << w[i] << " \n"[i == k];
        // // }
        // int l = 1, r = n;
        // for (int i = 1; i <= k; i++) {
        //     ans += a[r];
        //     if (w[i] == 1)
        //         ans += a[r];
        //     else
        //         ans += a[l];
        //     l += w[i] - 1;
        //     r--;
        //     // cout << "ans == " << ans << endl;
        // }
        // int ans2 = 0;
        // l = n;
        // r = n;
        // sort(w + 1, w + k + 1);
        // for (int i = 1; i <= k; i++) {
        //     ans2 += a[r];
        //     l = r - (w[i] - 1);
        //     ans2 += a[l];
        //     r = l - 1;
        //     // cout << "ans2 == " << ans2 << endl;
        // }
        // cout << max(ans2, ans ) << endl;
        int fk = 0;
        int l = 1;
        int r = n;
        while (f) {
            fk += a[r] * 2;
            r--;
            f--;
        }
        sort(w + 1, w + k + 1, greater<int>());
        for (int i = 1; i <= k; i++) {
            if (w[i] == 1) {
                break;
            } else {
                fk += a[r] + a[l];
                r--, l++;
                w[i] -= 2;
                l+=w[i];
            }
        }
        cout << fk << endl;
    }
}