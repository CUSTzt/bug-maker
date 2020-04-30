#include<bits/>
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
char str[maxn];
ll v[maxn];
int main() {
    CASET {
        scanf("%s", str);
        ll len = 1;
        int k = 1;
        ll ans = 0;
        for (int i = 1; str[i]; i++) {
            if (str[i - 1] != str[i]) {
                ans += len * len;
                v[k++] = len;
                len = 1;
            } else
                len++;
        }
        v[k++] = len;
        ans += len * len;
        v[0] = 0;
        v[k] = 0;
        ll MAX = ans;

        for (int i = 1; i < k - 1; i++) {
            if (v[i + 1] == 1) {
                ll before =
                    v[i] * v[i] + v[i + 1] * v[i + 1] + v[i + 2] * v[i + 2];
                ll now =
                    (v[i] + v[i + 1] + v[i + 2]) * (v[i] + v[i + 1] + v[i + 2]);
                MAX = max(MAX, ans - before + now);
            } else {
                ll before = v[i] * v[i] + v[i + 1] * v[i + 1];
                ll now =
                    (v[i] + 1) * (v[i] + 1) + (v[i + 1] - 1) * (v[i + 1] - 1);
                MAX = max(MAX, ans - before + now);
            }
            if (v[i] == 1) {
                ll before =
                    v[i - 1] * v[i - 1] + v[i] * v[i] + v[i + 1] * v[i + 1];
                ll now =
                    (v[i - 1] + v[i] + v[i + 1]) * (v[i - 1] + v[i] + v[i + 1]);
                MAX = max(MAX, ans - before + now);
            } else {
                ll before = v[i] * v[i] + v[i + 1] * v[i + 1];
                ll now =
                    (v[i] - 1) * (v[i] - 1) + (v[i + 1] + 1) * (v[i + 1] + 1);
                MAX = max(MAX, ans - before + now);
            }
        }
        printf("Case #%d: %lld\n", __CS, MAX);
    }
    return 0;
}