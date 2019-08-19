#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
typedef long long LL;
int father[maxn];
struct node
{
    int u,v,val;//u-v之间边权为val
}edge[maxn];
bool cmp(node a,node b)//按照边权小到大排序
{
    return a.val<b.val;
}
int Find(int x)//并查集查找父节点
{
    if(father[x]==x) return father[x];
    return father[x]=Find(father[x]);
}
void Union(int x,int y)//合并
{
    int fa=Find(x);
    int fb=Find(y);
    if(fa!=fb) father[fb]=fa;
}
int kruskal(int n,int m)
{
    sort(edge,edge+m,cmp);
    for(int i=0;i<=n;i++) father[i]=i;//初始化并查集
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int fa=Find(edge[i].u);
        int fb=Find(edge[i].v);
        if(fa!=fb)//如果u，v属于不同集合，进行合并，加入边权
        {
            Union(edge[i].u,edge[i].v);
            ans+=edge[i].val;
        }
    }
    return ans;
}
int main()
{
    int n;    //n个顶点  m条边 
    while(scanf("%d",&n)&&n)
    {
        int m=n*(n-1)/2;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].val);
        }
        printf("%d\n",kruskal(n,m));
    }
    return 0;
}