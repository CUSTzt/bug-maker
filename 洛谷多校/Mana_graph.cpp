#include<bits/stdc++.h>
#define ll long long
#define maxn 42
using namespace std;
const int mod = 998244353;
int n,m;
int e[maxn][maxn];
int a[maxn],b[maxn];
bool vis[maxn];
int ansa,ansb;
void dfs(int u,int A,int B)
{
	if(u==n)
	{
		ansa+=A;ansb+=B;
		ansa%=mod;ansb%=mod;
		return;
	}
	if(vis[u])
	{
		dfs(u+1,A,B);
		return;
	}
	int d=0;
	for(int i=u+1;i<n;++i)if(e[u][i]&&!vis[i])d++;
	if(!d)dfs(u+1,1ll*A*(a[u]+1)%mod,1ll*B*(b[u]+1)%mod);
	else
	{
		dfs(u+1,A,B);
		vector<int> p;p.clear();
		for(int i=u+1;i<n;++i)if(e[u][i]&&!vis[i])vis[i]=1,p.push_back(i);
		dfs(u+1,1ll*A*a[u]%mod,1ll*B*b[u]%mod);
		for(int x:p)vis[x]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int u,v,i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		u--;v--;
		e[u][v]=e[v][u]=1;
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)if(i!=j)e[i][j]^=1; 
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	for(int i=0;i<n;++i)scanf("%d",&b[i]);
	dfs(0,1,1);
	ansa--;ansb--;
	ansa=(ansa+mod)%mod;ansb=(ansb+mod)%mod;
	int ans=1ll*ansa*ansb%mod;
	printf("%d\n",ans);
}
