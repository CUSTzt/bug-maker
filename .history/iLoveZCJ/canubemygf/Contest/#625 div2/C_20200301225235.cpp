#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
//#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
const int maxn = 2e5+7;
using namespace std;
#define int long long 
struct node
{
    int to,w,next;
}edge[maxn];
int head[maxn], cnt;
int dis[maxn], vis[maxn],zz[maxn];
void init()
{
    memset(head,-1,sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    cnt = 0;
}
 
void add(int u,int v,int w)
{
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int n , m , u , v , k , p[maxn], s , t; 
/*void dijkstra()
{
    //dis[s] = 0;
    //for(int i = 1; i <= n-1; i++)
    {
        int mi = inf, now;
      //  for(int j = 1; j <= n; j++) //找离源点最近的一个点
        {
            if(vis[j] == 0 && dis[j] < mi)
            {
                mi = dis[j];
                now = j;  //最近点
            }
        }
        vis[now] = 1; //标记最近点
        for(int i = head[now]; i != -1; i = edge[i].next) //遍历以now为起点的边
        {
            int v = edge[i].to; //v代表以now为起点的边的终点
            if(dis[v] > dis[now] + edge[i].w) //能否松弛？
            {
                dis[v] = dis[now] + edge[i].w; //松弛操作
            }
        }
    }
}
*/
int32_t main()
{
    cin >> n >> m;
    init();
    for(int i = 0; i<m; i++){
        cin >> u >> v;
        add(v, u , 1);
    }
    cin >> k ;
    for(int i = 1; i <= k;i++)
        cin>>p[i];
    dis[p[k]] = 1;
    zz[p[k]]=1;
    queue<int> q;
    q.push(p[k]);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i = head[u];i!=-1;i=edge[i].next){
            v=edge[i].to;
            if(!dis[v]){
                dis[v] = dis[u]+1;
                q.push(v);
            }
            if(dis[v] == dis[u]+1)
                zz[v]+=1;
        }
    }
    int mn = 0, mx = 0;
    for(int i =2; i <= k; i++){
        if(dis[p[i]]+1!=dis[p[i-1]]){
            mx+=1;
            mn+=1;
        }else {
            if(zz[p[i-1]]){
                mx++;
            }
        }
    }
    cout << mn << ' ' <<mx <<endl;
}