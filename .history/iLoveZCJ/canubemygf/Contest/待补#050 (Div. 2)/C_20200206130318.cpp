/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-06 11:22:28
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , k , l[maxn], r[maxn];
double dp[maxn], p[maxn];
ll Cnt(int n){
    ll ans = 0, x = 1, cnt = 0, high , num = n;
    while(num){
        high = num % 10 ;
        num /= 10;
        cnt++;
    }for(int i = 1; i < cnt; i++, x*=10){
        ans += x;
    }if(high > 1) ans+= x;
    else ans += n-x+1;
    return ans;
}
int32_t main()
{
    close;
    while(cin >> n){
        for(int i = 0; i < n ; i++){
            cin >> l[i] >> r[i];
            p[i] = 1.0 * Cnt(r[i]) - Cnt(l[i]-1ll) / (r[i] - l + 1);
        } 
        cin >> k;
        memset(dp , 0 , sizeof dp);
        dp[0] = 1.0;
        for(int i = 1; i <= n;i++){
            for(int j = n; j >= 0; j--){
                dp[j] = dp[j-1] * (1.0 - p[i]);
                if(j > 0)dp[j] += dp[j-1] * p[i];
            }
        }double ans = 0.0;
        for(int i = 0; i <= n; i++){
            if(i * 100 > n*k)ans+=dp[i];
        }printf("%.10f\n",ans);
    }
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/