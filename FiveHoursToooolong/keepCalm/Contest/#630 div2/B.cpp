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
int n, a[maxn];
int fa[1110];
bool isprime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int main() {
    // close;
    CASET {
        int n;
        cin >> n;
        int a[n + 10];
        int ans[n + 10];
        int vis[15] = {0};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int cnt = 0;
        map<int, int> zcj;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 11; j++) {
                int ps = 0;
                if (a[i] % pr[j] == 0) {
                    ps = 1;
                    if (vis[j] == 0) {
                        vis[j] = 1;
                        cnt++;
                        zcj[j] = cnt;
                    }
                    ans[i] = zcj[j];
                    ps = 1;
                }
                if (ps) break;
            }
        }
        cout << cnt << endl;
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " \n"[i == n];
        }
    }
}