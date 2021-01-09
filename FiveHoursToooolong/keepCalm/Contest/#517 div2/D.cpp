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
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 2500;
constexpr int mod = 1e9 + 7;
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
int f[maxn][maxn], n, k, t, v[maxn][maxn];
char s[maxn][maxn];
//others
int32_t main() {
    close;
    cin >> n >> k;
    if (k >= 2 * n - 1) {
        for (int i = 0; i < 2 * n - 1; i++) cout << 'a';
        return 0;
    }
    FOR(i, 1, n + 1) cin >> s[i] + 1;
    FOR(i, 1, n + 1) FOR(j, 1, n + 1) {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]) + (s[i][j] == 'a');
    }
    FOR(i, 1, n + 1) FOR(j, 1, n + 1) {
        if (i + j - 1 - k <= f[i][j]) t = max(i + j, t);
    }
    FOR(i, 1, n + 1) {
        if (t - i > 0 && t - i <= n && t - 1 - k <= f[i][t - i])
            v[i][t - i] = 1;
    }
    // cout << " t == " << t << endl;
    for (int i = 1; i < t; i++) {
        cout << 'a';
    }
    if (!t) {
        cout << s[1][1];
        t = 2;
        v[1][1] = 1;
    }

    // cout << "t ===" <<  t << endl;
    for (int i = t + 1; i <= 2 * n; i++) {
        char c = 'z';
        for (int j = 1; j <= n; j++) {
            if (i - j > 0 && i - j <= n && (v[j - 1][i - j] || v[j][i - j - 1]))
                c = min(c, s[j][i - j]);
        }
        for (int j = 1; j <= n; j++) {
            if (i - j > 0 && i - j <= n &&
                (v[j - 1][i - j] || v[j][i - j - 1]) && s[j][i - j] == c)
                v[j][i - j] = 1;
        }
        cout << c;
    }
}