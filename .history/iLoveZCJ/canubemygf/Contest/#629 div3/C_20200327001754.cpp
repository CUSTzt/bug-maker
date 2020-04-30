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
#define CASET           \
    int ___T;           \
    scanf("%d", &___T); \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
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
const int N = 1e6 + 100;
int a[N], tp, num[N], cnt[N], P[N], SF[N], ACNT[N], BCNT[N];
int ans = linf, n, k, m, zb, zz;
void pre() {
    for (int i = 1; i <= n; i++) {
        zb++;
        if (a[i] == a[i + 1])
            continue;
        else {
            num[++m] = a[i];
            cnt[m] = zb;
            zb = 0;
        }
    }
}
void check() {
    for (int i = 1; i <= m; i++) {
        tp = k - cnt[i];
        ll aa=1ll;
        if (i > 1 && ACNT[i] >= tp) ans = min(ans, aa*tp + P[i]);
        if (i > 1 && i < m) ans = min(ans, aa*P[i] + tp + SF[i]);
        if (i < m && BCNT[i] >= tp) ans = min(ans, tp + SF[i]);
        if (tp < 1) {
            cout << 0;
            exit(0);
        }
    }
}
void calc() {
    for (int i = 1; i <= n + 1; i++) {
        zz--;
        ACNT[i] = cnt[i - 1] + ACNT[i - 1];
        P[i] = P[i - 1] + ACNT[i - 1] * (num[i] - num[i - 1]) +
               cnt[i - 1] * (num[i] - num[i - 1] - 1);
    }
    for (int i = m - 1; i >= 1; --i) {
        zz++;
        BCNT[i] = BCNT[i + 1] + cnt[i + 1];
        SF[i] = BCNT[i + 1] * (num[i + 1] - num[i]) + SF[i + 1] +
                cnt[i + 1] * (-num[i] + num[i + 1] - 1);
    }
}
int32_t main() {
    close;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    pre();
    calc();
    check();
    return cout << ans << endl, 0;
}