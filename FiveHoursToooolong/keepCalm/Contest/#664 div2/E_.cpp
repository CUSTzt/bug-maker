#include<bits/stdc++.h>
#define pb push_back
#define ll long long 
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define frep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 2E5+10;
const ll MOD = 1E9+7;

int n,m,k;
int s[N][2];
vector<int>G[N];
ll sum[10][10];
ll cnt,rd[N],ans[10],ct=0;

// rd[i]: 节点i的点权（hash）
// cnt: 节点1~n的点权和
// ans[]: 枚举的k元组
// ct: 满足条件的k元组数量
// sum[i][j]: 出度为i的所有点的第j小的边对应的点权和


void check()
{
	ll v=0;
	rep(i,1,k) v+=sum[i][ans[i]];
	if(v==cnt) ct++;
	return;
}

void dfs(int d){
	if(d>k) return check();
	for(ans[d]=1;ans[d]<=d;ans[d]++) dfs(d+1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		s[w][0]=u,s[w][1]=v;
	}
	rep(i,1,m)  G[s[i][0]].pb(s[i][1]);
	rep(i,1,n) rd[i]=rand()%MOD,cnt+=rd[i];
	// cout << "cnt == " << cnt << endl;
	rep(i,1,n)rep(j,0,G[i].size()-1)
	sum[G[i].size()][j+1]+=rd[G[i][j]];
	
	dfs(1);
	cout<<ct;
} 
