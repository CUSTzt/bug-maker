/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-13 20:22:59
 * @Description: You build it, You run it.  
 ***********************************************/
//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#define ll long long
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
#define eps 1e-8
using namespace std;
//prim 算法  类似与dijkstra算法   总是维护最小生成树的一部分
//prim 算法适用于稠密图，  kruskal算法适用于 稀疏图


//假设现在已经求得的生成树的顶点的集合是x
const int max_v = 110;
int cost [max_v][max_v];    //cost[u][v]表示边e=(u,v)的权值(不存在的时候设为inf)
int mincost[max_v];         //从集合x出发的边到每个顶点的最小权值
bool used[max_v];           //顶点i是否包含在集合x中
int V;                      //顶点数
int prim(){
	for(int i = 0; i < V; i++){
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;
	while(true){
		int v = -1;
		//从不属于x的顶点中选取从x到其权值最小的顶点
		for(int u = 0; u < V; u++){
			if(!used[u] && (v == -1|| mincost[u] < mincost[v]))v = u;
		}
		if(v == -1 )break;
		used[v] = true; //把顶点v加入x
		res += mincost[v]; //把边的长度加到结果里
		for(int u = 0; u < V;u++){
			mincost[u] = min(mincost[u],cost[v][u]);
		}
	}
	return res;
}

int main()
{
	while(cin>>V&&V){
		for(int i = 0; i < V;i++){
			for(int j = 0; j < V;j++){
				cin>>cost[i][j];
			}
		}
		cout << prim()<<endl;
	}
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
