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
int n, m, x[10], y[10], zz, ans;
int black(int x, int y) { return x * y / 2; }
int white(int x, int y) { return x * y - black(x, y); }
int32_t main() {
    CASET {
        cin >> n >> m;
        for (int i = 1; i < 5; i++) {
            cin >> x[i] >> y[i];
        }
        int zcj = black(x[2], y[2]) - black(x[1] - 1, y[2]) -
                  black(x[2], y[1] - 1) + black(x[1] - 1, y[1] - 1);
        int zb = white(x[4], y[4]) - white(x[3] - 1, y[4]) -
                 white(x[4], y[3] - 1) + white(x[3] - 1, y[3] - 1);
        ans = n * m / 2 - zcj + zb;
        x[3] = max(x[3], x[1]);
        x[4] = max(x[4], x[2]);
        y[3] = max(y[3], y[1]);
        y[4] = max(y[4], y[2]);
        if(x[3] < x[4] && y3)
    }
}