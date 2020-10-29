#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
// #include <random>
#include <cmath>
// #include <chrono>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <cassert>
//#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,s,t,k,c[1001];
ll f[1001];
vector < pair<int,int> > g[1001],w[1001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		int a,b,p; scanf("%d%d%d",&a,&b,&p);
		g[a].push_back(make_pair(b,p)),w[b].push_back(make_pair(a,p));
	}
	scanf("%d%d%d",&s,&t,&k);
	if(s==t) k++;
	memset(f,37,sizeof f);
	f[t] = 0;
	priority_queue < pair<ll,int> , vector< pair<ll,int> >, greater< pair<ll,int> > > q;
	q.push(make_pair(0ll,t));
	while(!q.empty()) {
		int x = q.top().second; ll dis = q.top().first; q.pop();
		for(int i=0;i<w[x].size();i++) {
			int y = w[x][i].first, p = w[x][i].second;
			if(f[y]>dis+p) {
				f[y] = dis + p;
				q.push(make_pair(f[y],y));
			}
		}
	}
	q.push(make_pair(f[s],s));
	bool flag = 0;
	while(!q.empty()) {
		int x = q.top().second; ll dis = q.top().first - f[x]; q.pop();
		c[x]++;
		if(x==t && c[x]==k) {
			printf("%lld\n",dis);
			flag = 1;
			break;
		}
		for(int i=0;i<g[x].size();i++) {
			int y = g[x][i].first, p = g[x][i].second;
			if(c[y]<k) {
				q.push(make_pair(dis+p+f[y],y));
			}
		}
	}
	if(!flag) puts("-1");
	return 0;
}