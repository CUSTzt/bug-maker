#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,p,q,r;
int X[105],Y[105],H[105],S[1000005],K[1000005];
ll dis[105][10005];
namespace SSSP
{
	int head[10005],p;
	struct edge
	{
		int to,next;
		ll w;
	}e[20005];
	void addedge(int u,int v,ll w)
	{
		e[++p].to=v;e[p].w=w;e[p].next=head[u];head[u]=p;
		e[++p].to=u;e[p].w=w;e[p].next=head[v];head[v]=p;
	}
	bool used[10005];
	void dij(int s,ll *d)
	{
		for(int i=1;i<=n;++i)d[i]=(ll)1e15,used[i]=0;
		priority_queue< pair<ll,int> > q;
		q.push(make_pair(0,s));
		d[s]=0;
		while(!q.empty())
		{
			int u=q.top().second;q.pop();
			if(used[u])continue;
			used[u]=1;
			for(int i=head[u];i;i=e[i].next)
			{
				int v=e[i].to;
				ll w=e[i].w;
				if(d[v]>d[u]+w)d[v]=d[u]+w,q.push(make_pair(-d[v],v));
			}
		}
	}
}
namespace Maxflow
{
	const int inf = 1000000007;
	int head[20005],p;
	struct edge{int to,next,f;}e[200005];
	void init()
	{
		memset(head,-1,sizeof(head));
		memset(e,0,sizeof(e));
		p=0;
	}
	void addedge(int u,int v,int f)
	{
	    e[p].to=v;e[p].f=f;e[p].next=head[u];head[u]=p++;
	    e[p].to=u;e[p].f=0;e[p].next=head[v];head[v]=p++;
	}
	int dis[20005];
	bool bfs(int s,int t)
	{
	    memset(dis,0,sizeof(dis));
	    queue<int> q;q.push(s);dis[s]=1;
	    while(!q.empty())
	    {
	        int u=q.front();q.pop();
	        for(int i=head[u];i!=-1;i=e[i].next)
	        {
	            int v=e[i].to;
				int f=e[i].f;
	            if(f&&!dis[v])dis[v]=dis[u]+1,q.push(v);
	        }
	    }
	    return dis[t]!=0;
	}
	int dfs(int u,int maxf,int t)
	{
	    if(u==t)return maxf;
		int tmp=0;
	    for(int i=head[u];i!=-1&&tmp<maxf;i=e[i].next)
	    {
	        int v=e[i].to;
			int f=e[i].f;
	        if(f&&dis[v]==dis[u]+1)
	        {
	            int minn=min(maxf-tmp,f);
	            f=dfs(v,minn,t);
				tmp+=f;
				e[i].f-=f;e[i^1].f+=f;
	        }
	    }
	    if(!tmp)dis[u]=inf;
		return tmp;
	}
	int dinic(int s,int t)
	{
	    int ans=0;
		while(bfs(s,t))ans+=dfs(s,inf,t);
		return ans;
	}
}
int cnt[105];
bool check(ll D)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=r;++i)
	{
		ll dx=dis[K[i]][S[i]];
		if(dx>D)cnt[K[i]]++;
	}
	Maxflow::init();
	int flow=0;
	for(int i=1;i<=p;++i)Maxflow::addedge(0,i,cnt[i]),flow+=cnt[i];
	for(int i=1;i<=q;++i)Maxflow::addedge(p+i,p+q+1,H[i]);
	for(int i=1;i<=p;++i)
		for(int j=1;j<=q;++j)if(dis[i][Y[j]]<=D)Maxflow::addedge(i,p+j,1000000007);
	if(Maxflow::dinic(0,p+q+1)==flow)return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&p,&q,&r);
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		SSSP::addedge(u,v,w);
	}
	for(int i=1;i<=p;++i)scanf("%d",&X[i]);
	for(int i=1;i<=p;++i)SSSP::dij(X[i],dis[i]);
	for(int i=1;i<=q;++i)scanf("%d%d",&Y[i],&H[i]);
	for(int i=1;i<=r;++i)scanf("%d%d",&S[i],&K[i]);
	ll L=0,R=(ll)1e14,ans=(ll)1e14;
	while(L<=R)
	{
		ll M=(L+R)>>1;
		if(check(M))ans=M,R=M-1;
		else L=M+1;
	}
	cout<<ans<<endl;
}
