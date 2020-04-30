#include<bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define pb push_back
#define int long long
using namespace std;
const int N = 3e5 + 10;
int n, far[N], du[N], dis[N];
bool F[N];
pair<int, int> e[N];
vector<pair<int, int>> G[N];
int find(int u)
{
	return far[u] == u ? u : far[u] = find(far[u]);
}
int Union(int u, int v)
{
	if(find(u) != find(v)) far[far[u]] = far[v];
}
void dfs(int u, int Fa)
{
	dis[u] = dis[Fa] ^ 1;
	for(auto e : G[u])
		if(e.first != Fa) dfs(e.first, u);
}
signed main()
{
	ios;
	cin >> n;
	rep(i , 1 , n - 1)
	{
		int u, v;
		cin >> u >> v;
		du[u]++;
		du[v]++;
		e[i] = {u, v};
		G[u].pb({v, i});
		G[v].pb({u, i});
	}
	dfs(1, 0);
	int vis[2] = {0, 0};
	rep(i , 1 , n)
		if(du[i] == 1) vis[dis[i]] = 1;
	int mi, ma = 0;
	if(vis[0] && vis[1]) mi = 3;
	else mi = 1;
	rep(i , 1 , n - 1) far[i] = i;
	vector<int> ve;
	rep(i , 1 , n)
	{
		ve.clear();
		for(auto e : G[i])
			if(du[e.first] == 1) ve.push_back(e.second);
		if(ve.size() > 1)
		{
			int fst = ve[0];
			for(auto e : ve) Union(fst, e);
		}
	}
	rep(i , 1 , n - 1)
		if(far[i] == i) ++ ma;
	cout << mi << " " << ma << '\n';
	return 0;
}
