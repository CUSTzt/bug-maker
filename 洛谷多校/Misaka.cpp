#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<queue>
#define ll long long
#define INF 1000000000
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret;
}

#define M 1000005

int first[M],nxt[M],to[M],d[M],t,n,m;
int order[M],f[M],b[M],vis[M],cnt,ans;

void addedge(int s,int v)
{
	nxt[++t]=first[s];
	first[s]=t;
	to[t]=v;
	d[v]++;
}

void topsort(int x)
{
	vis[x]=1;
	order[++cnt]=x;
	for(int i=first[x];i;i=nxt[i])
	{
		int v=to[i];
		d[v]--;
		if(d[v]==0)topsort(v);
	}
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		addedge(a,b);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&d[i]==0)topsort(i);
	for(int i=1;i<=n;i++)
		if(!b[order[i]])
		{
			ans++;
			for(int j=first[order[i]];j;j=nxt[j])
				b[to[j]]=1;
			b[order[i]]=1;
		}
	printf("%d\n",ans);
	return 0;
}

