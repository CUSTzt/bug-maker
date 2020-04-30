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
#define SORT_UmaxnIQUE(c)      \
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
constexpr int maxn = 2e5 + 10, M = 205;
constexpr int ImaxnF = 0x3f3f3f3f;
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
int n, ans, a[maxn], vis[maxn], pre_cnt[maxn][210], zz[maxn], father[maxn],
    last[maxn], pre[maxn], ST[maxn], f[maxn];
void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= M; j++) pre_cnt[i][j] = pre_cnt[i - 1][j];
        pre_cnt[i][a[i]]++;
    }
    for (int j = 2; j <= M; j++) zz[j] = pre_cnt[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = zz[a[i]];
        zz[a[i]] = i;
    }
    for (int i = 1; i <= M; i++) {
        zz[i] = 0;
        father[i] = 0;
    }
    for (int i = n; i >= 1; i--) {
        if (zz[a[i]] == 0) {
            zz[a[i]] = i;
            father[a[i]] = i;
            zz[a[i]] = i;
        }
    }
    for (int i = 0; i <= 203; i++) {
        vis[i] = 0;
    }
    ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[a[i]]) {
            f[i] = father[a[i]];
            ST[i] = 1; 
            vis[a[i]] = 2;
        } else
            f[i] = pre[f[last[a[i]]]], ST[i] = ST[last[a[i]]] + P;
        last[a[i]] = i;
        if (i < f[i]) {
            int l = i + 1;
            int r = f[i] - 1;
            int ma = 0;
            for (int j = 1; j <= M; j++)
                ma = max(ma,  - pre_cnt[l - 1][j] + pre_cnt[r][j]);
            ans = max((ST[i] << 1) + ma, ans);
        }
    }
    cout << ans << endl;
}
int main() {
    CASET { solve(); }
}