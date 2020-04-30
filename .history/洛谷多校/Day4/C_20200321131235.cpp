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
double h, r, d;
double qiuque(double x) { return x * x * (3 * r - h) * PI / 3; }
vector<double> ans;
double ddd(double x) { return PI * x * r * r; }
int main() {
    cin >> h >> r >> d;
    double l = 0;
    double banqiu = 2 * PI * r * r * r / 3;
    double tot = 4.0*PI*r*r*r/3+PI*r*r
    while (l + d < r) {
        double zz = qiuque(l + d) - qiuque(d);
        l += d;
        ans.eb(zz);
    }
    double zz = banqiu - qiuque(l) + ddd(l + d - r);
    ans.eb(zz);
    while (l + d < r + h) {
        ans.eb(ddd(d));
        l += d;
    }
    if (l + d >= r) {
        ans.eb(banqiu + ddd(r + h - l));
    } else {
        ans.eb(ddd(r + h - l) + qiuque(l + d - h - r));
        while (l + d < r) {
            double zz = qiuque(h+2*r-l)-qiuque(h+2*r-(l+d));
            l += d;
            ans.eb(zz);
        }
        ans.eb(qiuque(h+2*r-l));
    }
    for (auto x : ans) {
        printf("%.10f\n", x);
    }
}