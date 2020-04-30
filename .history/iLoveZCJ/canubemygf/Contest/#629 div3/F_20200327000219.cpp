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
#define int long long
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
int n, m, k, zb;
int32_t main() {
    close;
    cin >> n >> k;
    ll ans = linf;
    vector<int> a(n), num(n), cnt(n), pre[n], suf(n), pcnt(n), scnt(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        zb++;
        if (a[i] != a[i + 1]) {
            m++;
            num[m] = a[i], cnt[m] = zb;
            zb = 0;
        }
    }
    for(int i = 1; i < m; i++) {
        pre[i] = pre[i - 1] + pcnt[i - 1] * (num[i] - num[i - 1]) +
                 cnt[i - 1] * (num[i] - num[i - 1] - 1);
        pcnt[i] = pcnt[i - 1] + cnt[i - 1];
    }
    for(int i = m-2; i>=0;i--){
        suf[i] = suf[i + 1] + scnt[i + 1] * (num[i + 1] - num[i]) +
                 cnt[i + 1] * (num[i + 1] - num[i] - 1);
        scnt[i] = scnt[i + 1] + cnt[i + 1];
    }
    for(int i = 0; i < m; i++) {
        int res = k - cnt[i];
        if (res <= 0) {
            puts("0");
            return 0;
        }
        if (i > 1 && i < m) ans = min(ans, pre[i] + suf[i] + res);

        if (i > 1 && pcnt[i] >= res) ans = min(ans, pre[i] + res);

        if (i < m && scnt[i] >= res) ans = min(ans, suf[i] + res);
    }
    cout << ans;
}