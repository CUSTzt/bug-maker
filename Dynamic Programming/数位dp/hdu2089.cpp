/****************************************************************
# @Author:      miniLCT
# @DateTime:    2019-10-19 22:17:07
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int dp[8][2],digit[8];
int dfs(int len , bool state, bool fp){
    if(!len)return 1;
    if(!fp && dp[len][state] != -1)return dp[len][state];
    int ret = 0,fpmax = fp ? digit[len] : 9;
    for(int i = 0; i <= fpmax;i++){
        if(i == 4 || state && i == 2)continue;
        ret += dfs(len-1, i == 6, fp && i == fpmax);
    }
    if(!fp)dp[len][state] = ret;
    return ret;
}
int f(int n){
    int len = 0;
    while(n){
        digit[++len] = n % 10;
        n /= 10;
    }return dfs(len ,false ,true);
}
int main()
{
    int a, b;
    memset(dp, 0xff , sizeof dp);
    while(~scanf("%d%d",&a,&b) , a||b){
        printf("%d\n",f(b) - f(a-1));
    }
    return 0;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
