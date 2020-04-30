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
constexpr int maxn = 5000;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
#define y2 FUCK

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int n, m, k, q;
int cnt[maxn][maxn], sum[maxn][maxn], ans[maxn][maxn];
int x1, x2, y1, y2;
void init() {
    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        ++cnt[x1][y1], --cnt[x2 + 1][y1], --cnt[x1][y2 + 1],
            ++cnt[x1 + 1][x2 + 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + cnt[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] =
                ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + sum[i][j];
        }
    }
}
void solve() {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (ans[x2][y2] - ans[x2][y1-1] - ans[x1-1][y2] + ans[x2-1][y2-1]) << endl;
    //cout << (ans[x2][y2]+ans[x1-1][y1-1]-ans[x1-1][y2]-ans[x2-1][y1]) << endl;
}
int main() {
    close;
    cin >> n >> m >> k >> q;

    init();
    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m;j++)
        cout << sum[i][j] <<" \n"[j == m];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m;j++)
        cout << ans[i][j] <<" \n"[j == m];
    }*/
    while (q--) {
        solve();
    }
}