#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
const int maxm=4e6+10;
int to[maxm],nt[maxm],head[maxn];
int toc[maxm],nc[maxm],hc[maxm];
int low[maxn],dfn[maxn],num;
int Stack[maxn],ins[maxn],c[maxn];
vector <int> scc[maxn];
int n,m,tot,top,cnt,tc;
void add(int x,int y){
	to[++tot]=y;nt[tot]=head[x];head[x]=tot;
}
void add_c(int x,int y){
	toc[++tc]=y;nc[tc]=hc[x];hc[x]=tc;
}
map<int,int> mp;
void tarjan(int x){
	dfn[x]=low[x]=++num;
	Stack[++top]=x;ins[x]=1;
	for(int i=head[x];i;i=nt[i]){
		int y=to[i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(ins[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		cnt++;int y;mp.clear();
		do{
			y=Stack[top--];ins[y]=0;
			c[y]=cnt,scc[cnt].push_back(y);
			if(y>=n){
				if(mp[y-n]){
					printf("NO\n");exit(0);
				}
			}
			if(y<n)
				if(mp[y+n]){
					printf("NO\n");exit(0);
				}
			mp[y]=1;
		}while(x!=y);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int t1,t2,t3;string s;
		cin>>t1>>t2>>t3>>s;
		if(s=="AND"){
			if(t3==0) add(t1+n,t2),add(t2+n,t1);
			else add(t1,t1+n),add(t2,t2+n);
		}
		else if(s=="OR"){
			if(t3==0) add(t1+n,t1),add(t2+n,t2);
			else add(t1,t2+n),add(t2,t1+n);
		}
		else{
			if(t3==0)
				add(t1,t2),add(t2,t1),add(t1+n,t2+n),add(t2+n,t1+n);
			else
				add(t1,t2+n),add(t2,t1+n),add(t1+n,t2),add(t2+n,t1);
		}
		
	}
	for(int i=0;i<2*n;i++)
		if(!dfn[i])	tarjan(i);
	printf("YES\n");
}