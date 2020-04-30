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
#define int long long
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
constexpr int N = 1e4 + 10;
ll p[N], vis[N], n, m; /*
int sieve(int n){
    for(int i = 2; i <= n; i++){
        if(!vis[i])p[++p[0]] = i;
        for(int j = 2; j <= n / i; j++)
        vis[i*j] = 1;
    }
    return p[0];
}*/
int prime[N];
bool is_prime[N];
int sieve(int n)
{
    int p = 0;
    for (int i = 0; i <= n; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime[++p] = i;
        for (int j = 0; j < p; j++)
        {
            if (prime[j] * i > n)
                break;
            is_prime[prime[j] * i] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
    return p;
}
void work()
{
    int ans = 1000;
    cin >> n;
    for (int i = 0; i <= p[0]; i++)
    {
        if (n % prime[i] == 0)
        {
            int cnt = 0;
            while (n % prime[i] == 0)
                n /= prime[i], cnt++;
            ans = min(ans, cnt);
        }
    }
    if (n == 1)
    {
        cout << ans << endl;
        return;
    }
    int fl = 0;
    int d = (int)pow(n, 1.0 / 4);
    for (int i = max(1ll, d - 10); i <= d + 10; i++)
    {
        if (i * i * i * i == n)
        {
            ans = min(ans, 4ll);
            fl = 1;
            break;
        }
    }
    if (fl)
    {
        cout << ans << endl;
        return;
    }
    d = (int)pow(n, 1.0 / 3);
    for (int i = max(1ll, d - 10); i <= d + 10; i++)
    {
        if (i * i * i == n)
        {
            ans = min(ans, 3ll);
            fl = 1;
            break;
        }
    }
    if (fl)
    {
        cout << ans << endl;
        return;
    }
    d = (int)pow(n, 1.0 / 2);
    for (int i = max(1ll, d - 10); i <= d + 10; i++)
    {
        if (i * i == n)
        {
            ans = min(ans, 3ll);
            fl = 1;
            break;
        }
    }
    if (fl)
    {
        cout << ans << endl;
        return;
    }
    puts("1");
    return;
}
int32_t main()
{
    p[0] = sieve(4000);
    CASET
    {
        work();
    }
}