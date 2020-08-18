#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
#define il inline
using namespace std;
const int N=1e6+100;
ll n,tot=0,cnt,ans,anss,st,ans2,ans3;
ll edge[2*N],head[N],ver[2*N],Next[2*N];
ll v[N],v2[N],r[N],d[N],dp[2*N],s[N];
il void add(int x,int y,int z)
{
    edge[++tot]=z,ver[tot]=y,Next[tot]=head[x],head[x]=tot;
}
il bool dfs(int now,int la)
{
    if(v[now]==1)
    {
        v[now]=2,r[++cnt]=now,v2[now]=1;
        return 1;
    }
    v[now]=1;
    for(int i=head[now];i;i=Next[i])
        if(i!=((la-1)^1)+1 && dfs(ver[i],i))
        {
            if(v[now]!=2)
                r[++cnt]=now,v2[now]=1,s[cnt]=s[cnt-1]+edge[i];
            else
            {
                s[st-1]=s[st]-edge[i];
                return 0;
            }
            return 1;
        }
    return 0;       
}//2、dfs找环
il void tree_dp(int now)
{
    v2[now]=1;
    for(int i=head[now];i;i=Next[i])
    {
        int y=ver[i];
        if(v2[y])
            continue;
        tree_dp(y);
        ans=max(ans,d[now]+d[y]+edge[i]);
        d[now]=max(d[now],d[y]+edge[i]);
    }
}//3、处理第一种情况
il ll brt(int root)
{
    st=cnt+1,ans2=0,ans3=0;
    dfs(root,0);
    for(int i=st;i<=cnt;i++)
    {
        ans=0;
        tree_dp(r[i]);
        ans2=max(ans2,ans);
        dp[i+cnt-st+1]=dp[i]=d[r[i]];
        s[i+cnt-st+1]=s[i+cnt-st]+s[i]-s[i-1];
    }
    deque<int> q;
    for(int i=st;i<=2*cnt-st+1;i++)
    {
        while(q.size() && q.front()<=i-cnt+st-1)
            q.pop_front();
        if(q.size()) 
            ans3=max(ans3,dp[i]+dp[q.front()]+s[i]-s[q.front()]);
        while(q.size() && dp[q.back()]-s[q.back()]<=dp[i]-s[i])
            q.pop_back();
        q.push_back(i);
    }//4、处理第二种情况
    cout << "root ===  " << root << "   max === " << max(ans2, ans3) << '\n';
    return max(ans2,ans3);//取大的答案
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int y,z;
        scanf("%d %d",&y,&z);
        add(i,y,z);
        add(y,i,z);
    }//1、输入
    for(int i=1;i<=n;i++)
        if(!v2[i])//如果没走过就走
            anss+=brt(i);//加上答案
    cout<<anss;
    return 0;
}