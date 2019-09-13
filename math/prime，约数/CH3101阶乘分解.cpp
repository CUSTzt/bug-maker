#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long p[N],vis[N],n,m;
long long zs(long long n)//素数筛
{
    for(long long i=2;i<=n;i++)
    {
        if (!vis[i])
            p[++p[0]]=i;
        for(long long j=2;j<=n/i;j++)
            vis[i*j]=1;
    }
}
long long power(long long a,long long b)//快速幂
{
    long long ans=1;
    while(b)
    {
        if (b&1)
            ans=ans*a;
        a*=a;
        b>>=1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    zs(n);
    for(long long i=2;i<=n;i++)
        if (!vis[i])
        {
            long long ans=0;
            cout<<i<<" ";
            for(long long k=1;power(i,k)<=n;k++)//统计p出现的次数
                ans=ans+n/power(i,k);
            cout<<ans<<endl;
        }
    return 0;
}

