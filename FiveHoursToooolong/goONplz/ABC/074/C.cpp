/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-07 20:47:05
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
ll mod = 1e9+7;
int a, b , c , d , e , f;
int dp[5050][5050];
double td = 0.0;
int tot = 0, ans = 0;
void dfs(int sugar , int water ){
    if(dp[sugar][water] != -1)return;
    dp[sugar][water] = 1;
    if(sugar *100 > e*water)return ;
    if(sugar + water > f)return ;
    if (tot==0 || sugar * tot > ans*(sugar+water)){
        if (water>0){
            ans = sugar;
            tot = sugar + water;
        }
    }
    dfs(sugar, 100*a+water);
    dfs(sugar, 100*b+water);
    dfs(sugar + c, water);
    dfs(sugar + d, water);
}
int main()
{
    cin >> a >> b >> c >> d >> e >> f;
    memset(dp , 0xff , sizeof dp);
    dfs(0, 0);
    cout << tot << ' ' << ans << endl;
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/