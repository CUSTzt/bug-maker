/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-15 14:16:51
 * @Description: You build it, You run it.
 ***********************************************/
//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int , int >P;  //first 最短路径，second 顶点编号
const int maxn = 1e6+10;
#define eps 1e-8
const int inf = 0x3f3f3f3f;
int N,R;
struct edge{
	int to ,dis;
	edge(int to,int dis ):to(to),dis(dis){}
};
vector<edge > G[maxn];
int dist[maxn];
int dist2[maxn];
void solve(){
	priority_queue<P,vector<P>,greater<P> >que;
	fill(dist+1 ,dist+N+1,inf);
	fill(dist2+1,dist2+N+1,inf);
	dist[1] = 0;
	que.push(P(0,1));

	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second,d = p.first;
		if(dist2[v] < d )continue;    //大于次短路，一定大于最短路，不管
		for(int i= 0; i < int(G[v].size());i++){
			edge e = G[v][i];   //枚举与v相邻的点
			int d2 = d + e.dis;   //s到v 的距离+v到e.to的距离
			if(dist[e.to] > d2){    //小于最短路，更新最短路
				swap(dist[e.to] ,d2);
				que.push(P(dist[e.to],e.to));
			}
			if(dist2[e.to] > d2&&dist[e.to] < d2){   //大于最短路小于次短路。跟新次短路
				dist2[e.to] = d2;
				que.push(P(dist2[e.to],e.to));
			}
		}
	}
	cout << dist2[N]<<endl;
}
int main()
{
	//cout<<inf<<endl;

	cin>>N>>R;
	for (int i = 1; i <= N; i++)
			G[i].clear();
	for(int i = 1; i <= R; i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back(edge(b,c));
		G[b].push_back(edge(a,c));
	}
	solve();
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
