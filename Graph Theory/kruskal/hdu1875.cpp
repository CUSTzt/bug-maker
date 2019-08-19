/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-13 10:47:49
 * @Description: You build it, You run it.  
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
const int maxn = 110;
#define eps 1e-8
using namespace std;
int T ,C;
int par[maxn];//父亲
int rk[maxn];//树的高度
//数组par表示的是父亲的编号，par[x] = x时，x是所在的树的根

//初始化n个元素
//初始化所有的元素的父亲都是它自己:
void init (int n){
    for(int i = 0;i < n;i++){
        par[i] = i;
        rk[i] = 0;
    }
}

// 查询树的根
//find函数, 每次向上找它的父亲， 直到找到它的根(根的特点是pa[i] == i)
int find(int x){
    /*if(par[x] == x){
        return x;
    }else {
        return par[x] = find(par[x]);
    }*/
    return par[x]==x?x:find(par[x]);
}

// 合并x和y所属的集合
void unite (int x ,int y){
    x = find(x);
    y = find(y);
    if(x == y)return ;
    if(rk[x] < rk[y]){
        par[x] = y;
    }else {
        par[y] = x;
        if(rk[x] == rk[y])rk[x]++;
    }
}

//判断x和y是否属于同一集合
bool same(int x ,int y){
    return find(x) == find(y);
}


double dist(int x,int y){
    return (double)sqrt((1.0*x*x)+(1.0*y*y));
}
struct Point {
    int x,y;
}point[maxn]; 
struct Edge{
    int from ,to ;
    double cost;
}edge[maxn];
bool cmp (Edge a,Edge b){
    return a.cost < b.cost; 
}
vector<Edge >edges;
void add(int x,int y,double cost){
    Edge e = {x,y,cost};
    edges.push_back(e);
}
void Kruskal(){
    init(C);
    double sum = 0.0;
    int tot = C;
    sort(edges.begin(),edges.end(),cmp);
    for(int i = 0; i < edges.size();i++){
        Edge v = edges[i];
        if(v.cost < 10|| v.cost >1000)continue;
        if(!same(v.from , v.to)){
            unite(v.from , v.to);
            tot--;
            sum += v.cost;
            //cout<<v.cost<<"  sasd"<<tot<<endl;
        }
    }
    if(tot == 1)printf("%.1lf\n",sum*100);
    else printf("oh!\n");
}
int main()
{
    cin>>T;
    while(T--){
        cin>>C;
        edges.clear();
        for(int i = 0; i < C;i++){
            cin>>point[i].x>>point[i].y;
        }
        for(int i = 0; i < C-1; i++){
                for(int j = i+1;j < C;j++){
                    add(i,j, dist(point[i].x - point[j].x,point[i].y - point[j].y));
                    //cout<<i<<" "<<j<<"  "<<"   "<<dist(point[i].x - point[j].x,point[i].y - point[j].y)<<endl;
                }
            }
        Kruskal();
    }

}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
