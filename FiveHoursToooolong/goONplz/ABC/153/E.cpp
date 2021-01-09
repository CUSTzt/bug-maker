/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-28 14:54:11
# @Description: You build it. You run it
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
int n , h , a, b;
int dp[maxn];
int main()
{
    cin >> h >> n;
    memset(dp , 0x3f , sizeof dp);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int j = 0; j <= h; j++){
            dp[a+j] = min(dp[a+j] , dp[j] + b);
            if(j+a >= h)if(dp[h] > dp[j+a])dp[h] = dp[j+a];
        }
    }cout << dp[h] << endl;
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/