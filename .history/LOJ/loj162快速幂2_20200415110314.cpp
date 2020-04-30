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
constexpr ll P = 998244352ll;
vector<ll> pl, pr;
int x, n, S;
LL mul(LL u, LL v, LL p) {
    return (u * v - LL((long double)u * v / p) * p + p) % p;
}
void pre() {
    S = sqrt(P) + 1;
    pl.resize(S + 10);
    pr.resize(S + 10);
    pl[0] = 1;
    cin >> x >> n;
    for (int i = 1; i <= S + 1; i++) {
        // pl[i] = pl[i - 1] * x % P;
        pl[i] = mul(pl[i - 1], x, P);
    }
    pr[0] = 1;
    for (int i = 1; i <= S + 1; i++) {
        // pr[i] = pr[i - 1] * pl[S] % P;
        pr[i] = mul(pr[i - 1], pl[S], P);
    }
}
void solve() {
    ll tp;
    scanf("%")
    ll ans = mul(pl[x % S], pr[x / S], P);
    cout << ans << endl;
    // cout << (pl[x % S] * pr[x / S] % P) << endl;
}
int main() {
    // close;
    pre();
    while (n--) {
        solve();
    }
}