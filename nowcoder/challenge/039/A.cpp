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
void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int& a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int calc(vi& a, vi& b) {
    int n = a.size();
    int ret = INF;
    int mx = b.size() ? b.back() : 0;
    for (int i = 0; i < n; i++) {
        int tp1 = (i == 0) ? 0 : a[i - 1];
        int tp2 = (a[n - 1] - a[i] + 1) / 2;
        ret = min(ret, max(tp1, tp2));
    }
    return max(ret, mx);
}
int main() {
    CASET {
        int x, n;
        cin >> n;
        vi a, b;
        while (n--) {
            cin >> x;
            if (x > 0) a.eb(x);
            if (x < 0) b.eb(-x);
        }
        if (a.size() == 0 && b.size() == 0) {
            cout << 0 << endl;
            continue;
        } else {
            SORT_UNIQUE(a);
            SORT_UNIQUE(b);
            cout << min(calc(a, b), calc(b, a)) << endl;
        }
    }
}