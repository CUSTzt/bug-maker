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
#define int long long
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
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int mod = 998244353;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
void umax(int &a, int b) {
    if (a < b) a = b;
}
void umin(int &a, int b) {
    if (a > b) a = b;
}
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
set<ll> S;
int n, q, v[maxn];
int p[maxn], t[maxn], inv[maxn], s[maxn];
int query(int l, int r) {
    if (l == 1) {
        ll A = (t[r - 1] + 1) % mod;
        ll B = s[r] % mod;
        return A * get_inv(B, mod) % mod;
    }
    ll A = (t[r - 1] - t[l - 2] + mod) % mod * get_inv(s[l - 1], mod) % mod;
    ll B = s[r] * get_inv(s[l - 1], mod) % mod;
    // cout << "A == " << A << "  B === " << B << endl;
    return A * get_inv(B, mod) % mod;
}
int32_t main() {
    close;
    cin >> n >> q;
    S.insert(1);
    S.insert(n + 1);
    v[1] = 1;
    int inv100 = get_inv(100, mod);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] = p[i] * inv100 % mod;
    }
    s[0] = 1, t[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] * p[i] % mod;
        t[i] = (t[i - 1] + s[i]) % mod;
    }
    ll ans = query(1, n);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (v[x]) {
            v[x] = 0;
            S.erase(x);
            auto L = S.lower_bound(x);
            // auto L = lower_bound(ALL(S),x);
            auto R = L;
            L--;
            // ans = (ans + query(*L, *R - 1)) % mod;
            // ans = (ans - query(*L, x - 1) + mod) % mod;
            // ans = (ans - query(x, *R - 1) + mod) % mod;
            add(ans, query(*L, *R - 1));
            dec(ans, query(*L, x - 1));
            dec(ans, query(x, *R - 1));
        } else {
            v[x] = 1;
            // auto L = lower_bound(ALL(S),x);
            auto L = S.lower_bound(x);
            auto R = L;
            L--;
            // ans = (ans - query(*L, *R - 1) + mod) % mod;
            // ans = (ans + query(*L, x - 1)) % mod;
            // ans = (ans + query(x, *R - 1)) % mod;
            dec(ans, query(*L, *R - 1));
            add(ans, query(*L, x - 1));
            add(ans, query(x, *R - 1));
            S.insert(x);
        }
        cout << ans << endl;
    }
}