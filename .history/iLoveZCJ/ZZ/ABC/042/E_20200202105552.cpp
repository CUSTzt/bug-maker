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
//把每个数字都转换成为一个01串，ling
ll ans , dp[45][1 << 18];
int32_t main()
{
    int n  ,x , y , z;
    cin >> n >> x >> y >> z;
    int ans = 1, S , nw;
    for(int i = 1; i <= n; i++){
        ans = ans * 10 % mod;
    }
    nw = (1 << (x-1)) | (1 << x+y-1) | (1 << (x+y+z-1));
    S = (1 << x+y+z) - 1;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= S; j++){
            for(int k = 1; k <= 10; k++){
                int T = (j << k) | (1 << k-1);
                T &= S;
                if((T & nw) != nw){
                    dp[i][T] = (dp[i][T] + dp[i-1][j]) % mod;
                }
            }
        }
    }
    for(int i = 0; i <= S; i++){
        ans = (ans +mod - dp[n][i]) % mod;
    }cout << ans << endl;
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/