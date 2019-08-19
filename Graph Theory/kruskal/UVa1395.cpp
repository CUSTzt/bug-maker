/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-13 12:38:33
 * @Description: You build it, You run it.
 ***********************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <set>
#include <cstdlib>
#include <map>
#include <queue>
#include <vector>
#include <utility> // std::pair, std::make_pair
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;//最大值
const int N=102;

int edge[N][N];
int p[N];
int n,m;
vector<pair<int, int>> vec;

int find(int x)
{
    return p[x]==x? x : p[x]=find(p[x]);
}
void unit(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a!=b)
        p[a]=b;
}
int krus(int x)
{
    int cnt=0;
    int fx=vec[x].first;
    int fy=vec[x].second;
    for(int i=0;i<=n;i++){
        p[i]=i;
    }
    for(int i=x;i<m;i++){
        int ex=vec[i].first;
        int ey=vec[i].second;
        if(find(ex)!=find(ey)){
            cnt++;
            if(cnt==n-1) return edge[ex][ey]-edge[fx][fy];
            unit(ex,ey);
        }

    }
    return INF;
}

bool cmd(pair<int, int> a,pair<int, int> b){
    return edge[a.first][a.second]<edge[b.first][b.second];
}
int sel()
{
    if(m<n-1||krus(0)==INF) return -1;
    int ans=INF;
    sort(vec.begin(),vec.end(),cmd);
    for(int i=0;i<m;i++)
    {
        int a=krus(i);
        if(a==INF) continue;
        ans=min(ans,a);
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&!(n==0&&m==0))
    {
        memset(edge,0,sizeof(edge));
        vec.clear();
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            edge[x][y]=edge[y][x]=z;
            vec.push_back(make_pair(x, y));
        }
        cout<<sel()<<endl;
    }
    return 0;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
