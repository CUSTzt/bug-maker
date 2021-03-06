#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
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
LL bin(LL x, LL n, LL MOD)
{
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1)
            ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
int n, m, k, a[20][20], sum[20];
int main()
{
    cin >> n >> m >> k;
    ll suma = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            suma += a[i][j];
        }
    }
    int ans = 0;
    if (k >= min(n, m))
    {
        cout << suma << endl;
        return 0;
    }
    for (int i = 0; i < (1 << m); i++)
    {
        int zz = __builtin_popcount(i);
        memset(sum, 0, sizeof sum);
        int res = 0;
        if (zz > k)
            continue;
        for (int j = 1; j <= n; j++)
        {
            for (int t = 0; t < m; t++)
            {
                if (1 << t & i)
                    res += a[j][t + 1];
                else
                    sum[j] += a[j][t + 1];
            }
        }
        sort(sum + 1, sum + 1 + n, greater<int>());
        for (int j = 1; j <= k - zz; j++)
            res += sum[j];
        ans = max(ans, res);
    }
    cout << ans << endl;
}