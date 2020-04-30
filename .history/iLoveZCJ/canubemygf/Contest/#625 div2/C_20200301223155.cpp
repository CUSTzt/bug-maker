//使用链式前向星实现dijkstra,使用链式前向星也可避免图中重边的问题
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int maxv=1000+5;
const int maxe=10000+5;
const int INF=0x3f3f3f3f;
struct Edge{
int next,to,weight;
};
Edge edges[maxe];
int d[maxv],head[maxv],v,e,cnt,st=1,en;
bool done[maxv];
//无向图
void add(int u,int V,int dist)
{
    edges[++cnt].next=head[u];
    edges[cnt].to=V;
    edges[cnt].weight=dist;
    head[u]=cnt;
    edges[++cnt].next=head[V];
    edges[cnt].to=u;
    edges[cnt].weight=dist;
    head[V]=cnt;
}
void dijkstra()
{
    memset(done,false,sizeof(done));
    memset(d,INF,sizeof(d));
    d[st]=0;
    priority_queue<PII,vector<PII>,greater<PII> >pq;
    while(!pq.empty()) pq.pop();
    pq.push(PII(d[st],st));
    while(!pq.empty())
    {
        PII k=pq.top();
        pq.pop();
        if(en==k.second) return;
        if(done[k.second]) continue;
        done[k.second]=true;
        for(int i=head[k.second];i!=0;i=edges[i].next)
        {
            if(k.first+edges[i].weight<d[edges[i].to]) {
                d[edges[i].to]=k.first+edges[i].weight;
                pq.push(PII(d[edges[i].to],edges[i].to));
            }
        }
    }
}
int main()
{
    cnt=0;
    scanf("%d%d",&v,&e);
    memset(head,0,sizeof(head));
    for(int i=0;i<e;i++)
    {
         int u,V,dist;
         scanf("%d%d%d",&u,&V,&dist);
         add(u,V,dist);
    }
    en=v;
    dijkstra();
    printf("%d\n",d[en]);
    return 0;
}