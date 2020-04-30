/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-11 13:19:22
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const ll mod = 998244353;
ll bin(ll x , ll n , ll MOD){
    ll ret = MOD != 1;
    for(x %= MOD; n ; n >>= 1, x = x * x % MOD)
        if(n & 1)ret = ret * x % MOD;
    return ret;
}
int n , k, a[maxn], mx = 0;
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/