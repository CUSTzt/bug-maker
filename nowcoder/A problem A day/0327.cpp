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
#define int long long
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
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 2e5 + 100;
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
int a[maxn], dp1[maxn], dp2[maxn], sum[maxn], n, k, ans;
int32_t main() {
    close;
    CASET {
        cin >> n >> k;
        memset(dp1, 0xcf, sizeof dp1);
        memset(dp2, 0xcf, sizeof dp1);
        ans = -linf;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        // dp1 之前一段的max  dp2 之后的一段
        for (int i = k; i <= n - k; i++) {
            dp1[i] = max(sum[i] - sum[i - k], dp1[i - 1]);
        }
        for (int i = n - k + 1; i >= k + 1; i--) {
            dp2[i] = max(sum[i + k - 1] - sum[i - 1], dp2[i + 1]);
        }
        for (int i = k; i <= n - k; i++) {
            ans = max(ans, dp1[i] + dp2[i + 1]);
        }
        cout << ans << endl;
    }
}