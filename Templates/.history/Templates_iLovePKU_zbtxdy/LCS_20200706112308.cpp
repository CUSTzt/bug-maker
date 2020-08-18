#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn =250*250;
const int inf=1000000000;
int s[maxn],g[maxn],d[maxn];
int num[maxn];//num[x]为整数x的新编号，num[x]=0表示x没有在A中出现过、
int N,p,q,x;
int main()
{
    int T,tt=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&p,&q);
        memset(num,0,sizeof(num));
        for(int i=1;i<=p+1;i++)
        {
            scanf("%d",&x);
            num[x]=i;
        }
        int n=0;
        for(int i=0;i<q+1;i++)
        {
            scanf("%d",&x);
            if(num[x])
                s[n++]=num[x];
        }
        //求解s[0]...s[n-1]的LIS
        for(int i=1;i<=n;i++)
           g[i]=inf;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int k=lower_bound(g+1,g+n+1,s[i])-g;//在g[1]~g[n]中查找
            d[i]=k;
            g[k]=s[i];
            ans=max(ans,d[i]);
        }
        printf("Case %d: %d\n",++tt,ans);
    }
    return 0;
}
// #include<bits/stdc++.h>
// #define maxn 100000+10
// using namespace std;
// int a[maxn],dp[maxn];
// vector<int>location[26];
// char s1[maxn],s2[maxn];
// void init(){
//     for(int i=0;i<=maxn;++i)
//         a[i]=dp[i]=0;
// }
// void LCS(){
//     init();
//     int i,j,k,w,ans,l,r,mid;
//     int lena=strlen(s1),lenb=strlen(s2);
//     for(i=0;i<26;i++)location[i].clear();
//     for(i=lenb-1;i>=0;--i)location[s2[i]-'a'].push_back(i);
//     for(i=0,k=0;s1[i];i++)
//         for(j=0;j<location[w=s1[i]-'a'].size();++j,++k)
//             a[k]=location[w][j];
//     dp[1]=a[0];
//     dp[0]=-1;
//     for(i=ans=1;i<k;++i){
//         l=0;r=ans;
//         while(l<=r){
//             mid=(l+r)>>1;
//             if(dp[mid]>=a[i])r=mid-1;
//             else l=mid+1;
//         }
//         if(r==ans)
//             ans++,dp[r+1]=a[i];
//         else if(dp[r+1]>a[i])dp[r+1]=a[i];
//     }
//     cout<<ans<<endl;
// }
// int main(){
//     while(scanf("%s%s",s1,s2)!=EOF)LCS();
//     return 0;
// }