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
ll zz[50];
void init() {
    zz[1] = 1;
    for (ll i = 2; i <= 31; i++) {
        zz[i] = zz[i - 1] * 4 + 1;
    }
    // for(ll i = 1; i <= 31; i++){
    //     cout << zz[i] << endl;
    // }
}
int main() {
    init();
    CASET {
        ll n, k;
        cin >> n >> k;
        if (n > 31) {
            cout << "YES " << n - 1 << endl;
            continue;
        }
        if (k > zz[n]) {
            cout << "NO\n";
            continue;
        }
        ll tot = 0, now = 1, j = 0, re = 0;
        while (now + tot <= k && j < n) {
            tot += now;
            now = now * 2 + 1;  // now更新为下轮操作需要操作的边缘圈的格数
            j++;  // 对边缘圈的小格各操作一次 那么每格的边长又小了一半
                  // 即由2^(n-j)变为2^(n-(j+1))
            re += zz[n - j] * (now - 2);
        }
        if (k > tot + re)
            printf("NO\n");  // 全部切到1*1小格的操作次数tot+re 仍然不够k次
        else
            printf("YES %I64d\n", n - j);  // n-j 即缩小到最后的 log2(边长)
    }
}