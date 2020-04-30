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
#define int long long 
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
int n, k, ks;
char a[maxn];
int trx[250000][30];
int zcj = 1;
int32_t main() {
    int tp;
    cin >> tp;
    while (tp--) {
        for (int i = zcj; i <= k; i++) {
            for (int j = 0; j < 28; j++) {
                trx[i][j] = 0;
            }
        }
        cin >> n >> k;
        scanf("%s", a + 1);
        for (int i = 1; i <= n; i++) {
            int zz = (i % k) == 0 ? k : (i % k);
            trx[zz][a[i] - 'a']++;
        }
        for (int i = 1; i <= k / 2; i++) {
            for (int j = 0; j < 28; j++) {
                trx[i][j] = trx[i][j] + trx[1 + k - i][j];
            }
        }
        int ret = 0;
        if (k & 1) {
            for (int i = zcj; i < k / 2 + 1; i++) {
                int ks = -INF;
                for (int j = 0; j < 27; j++) {
                    ks = max(trx[i][j], ks);
                }
                ret = ret + (n / k * 2 - ks);
            }
            // int pe = -INF;
            /*for (int j = 0; j < 27; j++) {
                pe = max(pe, trx[k / 2 + 1][j]);
            }*/
            int pe = *max_element(trx[k / 2 + 1], trx[k / 2 + 1] + 27);
            ret += n / k - pe;
        } else {
            for (int i = 1; i < k / 2 + 1; i++) {
                ks = -INF;
                for (int j = 0; j < 27; j++) {
                    ks = max(trx[i][j], ks);
                }
                int ks = *max_element(trx[i],trx[i]+28);
                ret = ret + (n / k * 2 - ks);
            }
        }
        cout << ret << endl;
    }
}