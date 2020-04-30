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
int n, m;
int flag[maxn];
vector<char> g[maxn];
int dfs(int x, int y) {
    if (x >= n || y >= m || g[x][y] == '#' || flag[x * m + y]) return 0;
    if (x == n - 1 && y == m - 1) return 1;
    if (x != 0 && y != 0) flag[x * m + y] = 1;
    return dfs(x + 1, y) || dfs(x, y + 1);
}
int main() {
    close;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        g[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                flag[i * m + j] = 2;
            }
        }
    }
    if (!dfs(0, 0)) {
        printf("0\n");
        for (int i = 0; i < n * m; i++) {
            cout << flag[i];
            if (i % m == 0 && i != 0) cout << endl;
        }
        return 0;
    }
    if (!dfs(0, 0)) {
        printf("1\n");
    } else
        printf("2\n");
    for (int i = 0; i < n * m; i++) {
        cout << flag[i];
        if (i % m == m-1 ) cout << endl;
    }
    return 0;
}