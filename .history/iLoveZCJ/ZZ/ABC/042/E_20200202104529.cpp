/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-29 21:30:34
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
//状压dp
ll ans , dp[45][1 << 18];
int32_t main()
{
    int n  ,x , y , z;
    cin >> n >> x >> y >> z;
    int ans = 1, S = 0, nw;
    for(int i = 1; i <= n; i++){
        ans = ans * 10 % mod;
    }
    nw = (1 << )
    
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/