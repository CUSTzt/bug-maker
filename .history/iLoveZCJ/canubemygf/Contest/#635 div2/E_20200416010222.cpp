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
constexpr int maxn = 1e6 + 10, N = 3500;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
// string s, t;
char s[N], t[N];
int dp[N][N], len1, len2, ans, len;
void work(int i, int j) {
    len = j - i + 1;
    char c = s[len + 1];
    if (i >= 2) {
        if (i - 1 > len2) {
            dp[i - 1][j] += dp[i][j], dp[i - 1][j] %= mod;
        } else {
            if (c == t[i - 1]) dp[i - 1][j] += dp[i][j], dp[i - 1][j] %= mod;
        }
    }
    if (j + 1 <= len1) {
        if (j + 1 > len2) {
            dp[i][j + 1] += dp[i][j], dp[i][j + 1] %= mod;
        } else {
            if (c == t[j + 1]) dp[i][j + 1] += dp[i][j], dp[i][j + 1] %= mod;
        }
    }
}
void solve() {
    cin >> s + 1 >> t + 1;
    len1 = strlen(s + 1);
    len2 = strlen(t + 1);
    FOR(i, 1, 1 + len1) {
        char c = s[1];
        if (i > len2) {
            dp[i][i] = 2;
        } else {
            if (c == t[i]) dp[i][i] = 2;
        }
    }
    FOR(len, 1, len1) FOR(i, 1, len1 + 1) {
        int j = i + len - 1;
        if (j > len1) break;
        work(i, j);
    }
    for (int i = len1; i >= len2; i--) 
    ans = (ans + dp[1][i]) % mod;
    
    cout << ans << endl;
}
int main() { solve(); }