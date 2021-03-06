/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-06 13:05:23
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long 
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
double dp[maxn], p[maxn];
int n;
/*ll cnt(ll n){
    ll num = n,cnt =0, x=1ll, high=0,ans = 0;
    while(num){
        high = num % 10 ;
        num /= 10;
        cnt++;
    }for(int i = 1; i < cnt; i++,x*=10){
        ans += x;
    }
    if(high>1)
        ans+=x;
    else if(high==1)
        ans+=n-x+1;
    return ans;
}*/
using lld = long long;
lld Cnt(lld n)
{
    lld ans=0,x=1,cnt=0,high=0,num=n;
    while(num)
    {
        high=num%10;
        num/=10;
        cnt++;
    }
    for(int i=1;i<cnt;i++,x*=10)
        ans+=x;
    if(high>1)
        ans+=x;
    else if(high==1)
        ans+=n-x+1;
    return ans;
}
 
int32_t main()
{
    int n,k;
    lld l,r;
    cin >>n;
    {
        for(int i=1;i<=n;i++)
        {
            cin >> l >> r;
            lld temp=Cnt(r)-Cnt(l-1);
            p[i]=1.0*temp/(r-l+1);
        }
        scanf("%lld",&k);
        memset(dp,0,sizeof dp);
        dp[0]=1.0;
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=0;j--)
            {
                dp[j]=dp[j]*(1.0-p[i]);
                if(j>0)
                dp[j]+=dp[j-1]*p[i];
            }
        }
        double ans=0.0;
        for(int i=0;i<=n;i++)
            if(i*100>=n*k)
                ans+=dp[i];
        printf("%.15lf\n",ans);
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/