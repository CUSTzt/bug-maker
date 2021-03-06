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
ll m, n;
const LL p_max = 5E4 + 100;
LL mu[p_max], dd[p_max], sum_mu[p_max];
void get_mu()
{
    mu[1] = 1;
    static bool vis[p_max];
    static LL prime[p_max], p_sz, d;

    FOR(i, 2, p_max)
    {
        if (!vis[i])
        {
            prime[p_sz++] = i;
            mu[i] = -1;
        }
        for (LL j = 0; j < p_sz && (d = i * prime[j]) < p_max; ++j)
        {
            vis[d] = 1;
            if (i % prime[j] == 0)
            {
                mu[d] = 0;
                break;
            }
            else
            {
                mu[d] = -mu[i];
            }
        }
    }
    //cout << " ----- " << endl;
    for (int i = 1; i < p_max; i++)
    {
        sum_mu[i] = sum_mu[i - 1] + mu[i];
    }
}
void get_dd()
{
    for (int i = 1; i < p_max; i++)
    {
        for (int l = 1, r; l <= i; l = r + 1)
        {
            r = i / (i / l);
            dd[i] += 1ll * (i / l) * (r - l + 1);
        }
    }
}
ll ans;
void work()
{
    ans = 0;
    //cout <<"sss" <<endl;
    if (n > m)
        swap(n, m);
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = min(n / (n / l), m / (m / l));
        ans += (sum_mu[r] - sum_mu[l - 1]) * dd[n / l] * dd[m / l];
    }
    printf("%lld\n",ans);
}
int main()
{
    get_mu();
    get_dd();
    CASET
    {
        scanf("%lld%lld",&n,&m);
        work();
    }
}
