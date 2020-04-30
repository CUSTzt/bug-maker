#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
typedef long long lld;
const int oo=0x3f3f3f3f;
const lld OO=1LL<<61;
const int MOD=(1e9)+7;
const int maxn=1005;
double dp[maxn],p[maxn];
 
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
 
int main()
{
    int n,k;
    lld l,r;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d %I64d",&l,&r);
            lld temp=Cnt(r)-Cnt(l-1);
            p[i]=1.0*temp/(r-l+1);
        printf("p[%lld]===%.6f\n",i,p[i]);

        }
        scanf("%d",&k);
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
            if(i*100>=n*k){
                ans+=dp[i];cout<<"ans=="<<ans <<endl;}
        printf("%.15lf\n",ans);
    }
 
    return 0;
}
/**
1
1 2
50
2
1 2
9 11
50
*/
 
 
 
 