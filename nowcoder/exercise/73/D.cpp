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
#include <functional>
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
int n, q, k, a[maxn];
vector<int> p[maxn];
vector<pii> query[maxn];
ll l[maxn], s[maxn], ans[maxn];
int main() {
    close;
    cin >> n >> q >> k;
    for(int i = 1; i <= n; i++) l[i] = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]].eb(i);
    }
    if (k == 0) {
        while (q--) {
            cout << 0 << endl;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            int len = SZ(p[i]);
            for (int j = 0; j < len; j++) {
                if (j + k > len - 1) break;
                l[p[i][j]] = p[i][j + k] - 1;
            }
        }
        for (int i = n; i; i--) {
            umin(l[i - 1], l[i]);
        }
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + l[i];
        }
        for (int i = 1, x, y; i <= q; i++) {
            cin >> x >> y;
            query[y].eb(x, i);
        }
        function<ll(ll)> sqr = [&](ll x) { return x * (x - 1) / 2; };
        for (int i = 1, j = 0; i <= n; i++) {
            while (j < n && l[j + 1] == i) j++;
            for (auto [a, b] : query[i]) {
                int c = i - a + 1;
                ans[b] -= sqr(i) - sqr(a - 1);
                if(j >= a)c-=j-a+1,ans[b] += s[j] - s[a - 1];
                ans[b] += c * i;
            }
        }
        if (k > 1) {
            k--;
            for (int i = 1; i <= n; i++) {
                int len = SZ(p[i]);
                for (int j = 0; j < len; j++) {
                    if (j + k > len - 1) break;
                    l[p[i][j]] = p[i][j + k] - 1;
                }
            }
            for (int i = n; i; i--) {
                umin(l[i - 1], l[i]);
            }
            for (int i = 1; i <= n; i++) {
                s[i] = s[i - 1] + l[i];
            }
            for (int i = 1, j = 0; i <= n; i++) {
                while (j < n && l[j + 1] == i) j++;
                for (auto x : query[i]) {
                    int c = i - x.fi + 1;
                    ans[x.se] += sqr(i) - sqr(x.fi - 1);
                    if (j >= x.fi)
                        c -= j - x.fi + 1, ans[x.se] -= s[j] - s[x.fi - 1];
                    ans[x.se] -= 1ll * c * i;
                }
            }
        }
        for (int i = 1; i <= q; i++) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}