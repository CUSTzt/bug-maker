#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
    int ans=1;
    for(;y;y>>=1,x=1ll*x*x%MOD)
        if(y&1)ans=1ll*ans*x%MOD;
    return ans;
}
const int MAXN=200005;
 
int n,m,ut;
vector<int> G[MAXN];
int size[MAXN],to[MAXN];
vector<int> leaf[MAXN];
void dfs1(int u,int pa)
{
    if(G[u].size()==1)size[u]=1;
    int w=0;
    for(auto v:G[u])
    {
        if(v==pa)continue;
        dfs1(v,u);
        size[u]+=size[v];
        chkmax(w,size[v]);
    }
    if(G[u].size()>1 && max(w,m-size[u])<=m/2)ut=u;
}
void dfs2(int u,int pa,int g)
{
    if(G[u].size()==1)
    {
        size[u]=1;
        to[u]=g;
    }
    for(auto v:G[u])
    {
        if(v==pa)continue;
        dfs2(v,u,u==ut?v:g);
        size[u]+=size[v];
    }
}
priority_queue<pii,vector<pii>,less<pii> > pq;
int k;
pii ans[MAXN];
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
//  freopen("code.out","w",stdout);
    #endif
    int u,v;
    readint(n);
    if(n==1)return 0*printf("0\n");
    if(n==2)return 0*printf("1\n1 2\n");
    for(int i=1;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
    int rt;
    for(int i=1;i<=n;++i)
        if(G[i].size()==1)++m;
        else rt=i;
    dfs1(rt,-1);
    dfs2(ut,-1,0);
    for(int i=1;i<=n;++i)if(G[i].size()==1)leaf[to[i]].pb(i);
    for(int i=1;i<=n;++i)if(!leaf[i].empty())pq.push(mp(leaf[i].size(),i));
    while(!pq.empty())
    {
        int u=pq.top().y;pq.pop();
        if(pq.empty())
        {
            ans[++k]=mp(leaf[u].back(),rt);
            break;
        }
        int v=pq.top().y;pq.pop();
        ans[++k]=mp(leaf[u].back(),leaf[v].back());
        leaf[u].pop_back(),leaf[v].pop_back();
        if(!leaf[u].empty())pq.push(mp(leaf[u].size(),u));
        if(!leaf[v].empty())pq.push(mp(leaf[v].size(),v));
    }
    printf("%d\n",k);
    for(int i=1;i<=k;++i)printf("%d %d\n",ans[i].x,ans[i].y);
    return 0;
}