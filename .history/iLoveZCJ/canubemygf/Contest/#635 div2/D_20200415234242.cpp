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
using namespace std;
using LL = long long;
#define eps 1e-8
#define int long long
#define fi first
#define se second
#define eb emplace_back
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
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
void solve() {
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<int> r(nr + 1), g(ng + 1), b(nb + 1);
    vector<int> y, z;
    for (int i = 1; i <= nr; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= ng; i++) {
        cin >> g[i];
        y.eb(g[i]);
    }
    for (int i = 1; i <= nb; i++) {
        cin >> b[i];
        z.eb(b[i]);
    }
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    int ans = linf;
    for (int i = 1; i <= nr; i++) {
        int it = lower_bound(y.begin(),y.end(),r[i]) - y.begin();
        if(it != nr){
            int tp = (r[i]+g[it]) / 2;
            int iq = lower_bound(z.begin(),z.end(),r[i]) - z.begin();
            int x1 = g[i], x2=r[it]
        }
    }
}
int32_t main() {
    close;
    CASET { solve(); }
}