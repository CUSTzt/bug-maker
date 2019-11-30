#include<cstdio>
#include<cstring>
using namespace std;
const int num=505;
int map[num][num],in[num],n,m,ans[num],cnt;
void topo()
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(in[j]==0)
            {
                t=j;
                ans[cnt++]=t;
                in[j]--;
                break;
            }
        }
        for(j=1;j<=n;j++)
        {
            if(map[t][j]==1)
                in[j]--;
        }
    }
}
int main()
{
    int i,a,b;
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(in,0,sizeof(in));
        memset(map,0,sizeof(map));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            if(map[a][b]==0)
                in[b]++;
            map[a][b]=1;
        }
        cnt=0;
        topo();
        for(i=0;i<n-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
}
