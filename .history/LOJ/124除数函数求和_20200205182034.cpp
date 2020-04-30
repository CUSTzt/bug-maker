/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 17:58:34
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
using LL = long long;
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
bool vis[maxn];
int n , k , cnt , pri[maxn], f[maxn];
int32_t main()
{
    cin >> n >> k;
    f[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!vis[i])pri[++cnt] = i, f[i] = bin(i , k , mod);
        for(int j = 1; j <= cnt )
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/