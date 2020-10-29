#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
void umin(ll& a,ll t){if(t<a)a=t;}
const ll INF=1ll<<50;
#define MAXN 300011
struct DSU//并查集,用于求最小生成树
{
    ll fa[MAXN];
    void build(ll n){for(ll i=1;i<=n;++i)fa[i]=i;}
    ll find(ll x)
    {
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    bool uni(ll u,ll v)
    {
        u=find(u),v=find(v);
        if(u==v)return 0;
        fa[u]=v;return 1;
    }
}s;
struct edge
{
    ll u,v,w;
    bool operator <(const edge& t)const{return w<t.w;}
}e[MAXN];
std::vector<ll>g[MAXN];
bool used[MAXN];
ll Kru(ll n,ll m)
{
    std::sort(e+1,e+m+1);
    s.build(n);
    ll ans=0;
    for(ll i=1;i<=m;++i)
        if(s.uni(e[i].u,e[i].v))
        {
            ans+=e[i].w;
            g[e[i].u].push_back(e[i].v),g[e[i].v].push_back(e[i].u);
            used[i]=1;
        }
    return ans;
}
struct LCT//LCT,维护链上最大边权和严格次大边权
{
    ll fa[MAXN],son[MAXN][2],val[MAXN], maxv[MAXN],sec[MAXN],tag[MAXN], tot;
    void init(ll n){tot=n;}
    void pushup(ll x)//卡常过的pushup
    {
        ll l=son[x][0],r=son[x][1];
        maxv[x]=max(max(maxv[l],maxv[r]),val[x]);
        sec[x]=0;
        if(maxv[l]<maxv[x])umax(sec[x],maxv[l]);
        else umax(sec[x],sec[l]);
        if(val[x]<maxv[x])umax(sec[x],val[x]);
        if(maxv[r]<maxv[x])umax(sec[x],maxv[r]);
        else umax(sec[x],sec[r]); 
    }
    void pushdown(ll x)
    {
        if(tag[x])
        {
            std::swap(son[x][0],son[x][1]);
            tag[son[x][0]]^=1,tag[son[x][1]]^=1;
            tag[x]=0;
        }
    }
    bool not_root(ll x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
    void rotate(ll x)
    {
        ll y=fa[x],z=fa[y],k=(son[y][1]==x);
        if(not_root(y))son[z][son[z][1]==y]=x;
        fa[x]=z;
        son[y][k]=son[x][!k],fa[son[x][!k]]=y;
        son[x][!k]=y,fa[y]=x;
        pushup(y);//再pushu(x)就会TLE
    }
    ll s[MAXN];
    void splay(ll x)
    {
        ll top=0;
        s[++top]=x;
        for(ll y=x;not_root(y);y=fa[y])s[++top]=fa[y];
        while(top)pushdown(s[top--]);
        while (not_root(x))
        {
            ll y=fa[x];
            if(not_root(y))rotate((son[y][1]==x)==(son[fa[y]][1]==y)?y:x);
            rotate(x);
        }
        pushup(x);        
    }
    void access(ll x)
    {
        for(ll y=0;x;y=x,x=fa[x])
            splay(x),son[x][1]=y;
    }
    void make_root(ll x){access(x),splay(x),tag[x]^=1;}
    void link(ll x,ll y)
    {
        make_root(x);
        fa[x]=y;
    }
    void merge(ll x,ll y,ll v)
    {
        val[++tot]=v;
        link(x,tot),link(y,tot);
    }
    pll split(ll x,ll y)//求链上最大边权和严格次大边权
    {
        make_root(x),access(y),splay(y);
        return pll(maxv[y],sec[y]);
    }
}lct;
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=m;++i)e[i].u=read(),e[i].v=read(),e[i].w=read();
    ll sum=Kru(n,m);
    lct.init(n);
    for(ll i=1;i<=m;++i)
        if(used[i])lct.merge(e[i].u,e[i].v,e[i].w);
    ll ans=INF;
    for(ll i=1;i<=m;++i)
    {
        if(used[i])continue;
        pll mx=lct.split(e[i].u,e[i].v);
        if(mx.first<e[i].w)umin(ans,sum-mx.first+e[i].w);
        else umin(ans,sum-mx.second+e[i].w);
    }
    printf("%lld",ans);
    return 0;
}
