/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-13 13:54:21
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
#define ll long long
const int maxn = 105;
#define eps 1e-6
int par[maxn];//父亲
int rk[maxn];//树的高度
//数组par表示的是父亲的编号，par[x] = x时，x是所在的树的根

//初始化n个元素
//初始化所有的元素的父亲都是它自己:
void init (int n){
    for(int i = 1;i <= n;i++){
        par[i] = i;
        rk[i] = 0;
    }
}

// 查询树的根
//find函数, 每次向上找它的父亲， 直到找到它的根(根的特点是pa[i] == i)
int find(int x){
    return par[x]==x?x:find(par[x]);
}

// 合并x和y所属的集合
void unite (int x ,int y){
    x = find(x);
    y = find(y);
    if(x == y)return ;
    if(rk[x] < rk[y]){
        par[x] = y;
        //return 1;
    }else {
        par[y] = x;
        if(rk[x] == rk[y])rk[x]++;
        //return 1;
    }
}

//判断x和y是否属于同一集合
bool same(int x ,int y){
    return find(x) == find(y);
}


struct YUANXIN{
	double x,y,z,r;
}yx[maxn];

struct Ltk{
	double dis;
	int u,v;
}ltk[6000];
std::vector<Ltk> edges;
double dist(double a,double b,double c){
	return (double)sqrt(1.0*a*a+b*b+c*c);
}
bool cmp (Ltk a,Ltk b ){
	return a.dis < b.dis;
}
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n){
		int cnt = 0;
		init(n);
		double mindis = 0;
		for(int i = 1; i <= n ; i++){
			cin>>yx[i].x>>yx[i].y>>yx[i].z>>yx[i].r;
		}
		for(int i = 1; i <= n-1 ; i++){
			for(int j = i+1; j <= n; j++){
				double d = dist(yx[i].x-yx[j].x,yx[i].y-yx[j].y,yx[i].z-yx[j].z)-(1.0*yx[i].r+yx[j].r);
					ltk[cnt].u = i;
					ltk[cnt].v = j;
					//if(fabs(ltk[cnt].dis)<eps)ltk[cnt].dis = 0.000;
					ltk[cnt].dis = d >0?d:0;
					//if(fabs(ltk[cnt].dis)<eps)ltk[cnt].dis = 0;
					cnt++;
			}
		}
		sort(ltk, ltk+cnt,cmp);
		//init( n);
		for(int i = 0; i <= cnt ; i++){
			if(!same(ltk[i].u,ltk[i].v)){
				mindis += ltk[i].dis;
				//cout<<"i===="<<i<<"      dis ===="<<ltk[i].dis<<"      mindis===="<<mindis<<endl;
				unite(ltk[i].u,ltk[i].v);
			}
		}
		printf("%.3f\n", (mindis));	
	}
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
