//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
//target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define int LL
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int32_t(a.size())
#define ALL(x) (x).begin(), (x).end()
#define trav(a, x) for (auto &a : x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close                                                              \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), \
        cout << fixed << setprecision(10)
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
constexpr int mod = 1e9 + 7;  // 998244353
// mt19937 dlsrand(random_device{}());
// mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
// int rnd(int x) { return mrand() % x;}
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
void up() {
    string s, t;
    cin >> s >> t;
    if (s.size() < t.size()) {
        swap(s, t);
    }
    int n = s.size(), m = t.size();
    string ans = "";
    if (n % m == 0) {
        int fl = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i % m]) {
                fl = 0;
                break;
            }
        }
        if (fl) {
            cout << s << endl;
            return;
        }
    }
    for (int i = 0; i < n * m; i++) {
        ans += s[i % n];
    }
    int fl = 1;
    for (int i = 0; i < n*m; i++) {
        if (ans[i] != t[i % m]) {
            fl = 0;
            break;
        }
        if(ans[i] == t[i % m] and i && (i % m == 0) && (i % n == 0) && fl ){
            // cout << "i === " << i << endl;
            ans = ans.substr(0,i);
            break;
        }
    }
    if(fl)cout << ans << endl;
    else {
        cout << -1 << endl;
    }
}
int32_t main() {
    close;
    CASET { up(); }

    return 0;
}
/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
                    - William Butler Yeats
*/