#include<bits/stdc++.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200005


int cnt; int head[N];
struct edge{ int des; int next; }e[N<<1];
void ins(int u,int v){ ++cnt; e[cnt].des=v; e[cnt].next=head[u]; head[u]=cnt; }

int n; int a[N]; int dp[N];

void dfs1(int u,int f){
    if(a[u]==1) dp[u]=1;
    else        dp[u]=-1;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].des;
        if(v==f) continue;
        dfs1(v,u);
        dp[u]+=max(0,dp[v]);
    }
}
void dfs2(int u,int f){
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].des;
        if(v==f) continue;
        int tmp=dp[u];
        if(dp[v]>0) tmp-=dp[v];
        dp[v]+=max(tmp,0);
        dfs2(v,u);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    for(int i=1;i<n;++i){
        int u; int v; scanf("%d %d",&u,&v);
        ins(u,v); ins(v,u);
    }
    dfs1(1,0); dfs2(1,0);
    for(int i=1;i<=n;++i) printf("%d ",dp[i]);
    printf("\n");
    return 0;
}