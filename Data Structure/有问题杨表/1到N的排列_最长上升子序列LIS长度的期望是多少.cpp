#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using LL = long long;
constexpr int mod = 998244353;
constexpr int maxn = 1100;
ll inv[maxn], a[maxn], n, ans;
LL bin(LL x, LL n, LL MOD)
{
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1)
            ret = ret * x % MOD;
    return ret;
}
inline void dfs(int x, int y)
{
    if (!x)
    {
        ll res = 1;
        for (int i = 1; i <= n; ++i)
        {
            res = res * i % mod;
        }
        for (int i = 1; i < y; ++i)
        {
            for (int j = 1; j <= a[i]; j++)
            {
                int ct = a[i] - j;
                for (int k = i; k < y; k++)
                {
                    if (a[k] >= j)
                        ++ct;
                }
                res = res * inv[ct] % mod;
            }
            ans = (ans + res * res % mod * a[1] % mod) % mod;
        }
    }
    for (int i = 1; i <= x; i++)
    {
        if (y != 1 && i > a[y - 1])
            continue;
        a[y] = i;
        dfs(x - i, y + 1);
    }
}
int main()
{
    freopen("out.txt","w",stdout);
    // cin >> n;
    for (int i = 1; i <= 100; i++)
        {
            inv[i] = bin(i, mod - 2, mod);
        }
        cout << "begin" << endl;
    for (n = 1; n = 60; n++)
    {
        memset(a, 0 , sizeof a);//memset(inv , 0 , sizeof inv);
        ans = 0;
        dfs(n, 1);
        for (int i = 1; i <= n; i++)
        {
            ans = ans * inv[i] % mod;
        }
        cout <<"n === " << n << endl;
        cout << ans << endl;
    }
    return 0;
}