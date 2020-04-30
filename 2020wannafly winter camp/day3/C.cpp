#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long 
const int inf=2147483647;
int tt,n=0,m,to[18],v[18];
bool ok[1<<18];
int f[1<<18];
int s1,s2;
struct Edge{
    int x,y;
}e[200];
int32_t main()
{
    cin >> tt >> m;
    for(int i=1;i<=m;i++)
    {
        int x , y;
        cin >> x >> y;
        if(!v[x])v[x]=++n;if(!v[y])v[y]=++n;
        e[i].x=v[x],e[i].y=v[y];
    }
    for(int S=1;S<(1<<n);S++)
    {
        ok[S]=true;
        for(int i=1;i<=m;i++)
        if((1<<(e[i].x-1))&S&&(1<<(e[i].y-1))&S){ok[S]=false;break;}
    }
    f[0]=0;
    for(int S=1;S<(1<<n);S++)
    {
        f[S]=inf;
        for(int T=S;T;T=(T-1)&S)
        if(ok[T]&&f[S^T]!=inf)f[S]=min(f[S],f[S^T]+1);
    }
    printf("%d\n",f[(1<<n)-1]-1);
}
