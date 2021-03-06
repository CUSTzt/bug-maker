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
int mex(int p, int q)
{
    return p && q ? 0 : (p != 1 && q != 1 ? 1 : 2);
}
int mex(int p, int q, int r)
{
    int zz[] = {0, 0, 0, 0};
    zz[p] = zz[q] = zz[r] = 1;
    for (int i = 0; i < 4; i++)
        if (!zz[i])
            return i;
}
int n, x, y, z, f[maxn][3];
int main()
{
    CASET
    {
        scanf("%d%d%d%d", &n, &x, &y, &z);
        f[0][0] = f[0][1] = f[0][2] = 0;
        int d = (x + y) * (y + z) * (z + x);
        for (int i = 1; i <= d + d + d; i++)
        {
            int p = f[max(i - x, 0)][0], q = f[max(i - y, 0)][1], r = f[max(i - z, 0)][2];
            f[i][0] = mex(p, q, r);
            f[i][1] = mex(p, r);
            f[i][2] = mex(p, q);
        }
        int v = 0, s[4] = {0, 0, 0, 0};
        for (int i = 1; i <= n; i++)
        {
            long long p;
            scanf("%lld", &p);
            p = p > d + d ? p % d + d + d : p;
            int val = f[p][0], v0 = f[max(p - x, 0ll)][0], v1 = f[max(p - y, 0ll)][1], v2 = f[max(p - z, 0ll)][2];
            v ^= val;
            s[val ^ v0]++;
            s[val ^ v1]++;
            s[val ^ v2]++;
        }
        printf("%d\n", s[v]);
    }
}