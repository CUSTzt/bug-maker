#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1005;

int x[maxn],y[maxn],p[maxn];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
struct edge{
    int u,v,w;
    bool operator<(const edge&a)
     const {return w<a.w;}
}_e[maxn*maxn],e[maxn];
int dist(int a,int b){
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
int q[8][maxn],c[8],t[8];
int n,m,r,cnt;

void clear(){
    m=cnt=0;
}

ll solve(){
    ll ret=0;
    for(int i=1;i<n;i++){
        int x=find(e[i].u),y=find(e[i].v);
        if(x!=y){
            ret+=e[i].w;
            p[x]=y;
        }
    }
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    
    while(T--){
        clear();
        scanf("%d%d",&n,&r);
        for(int i=0;i<r;i++){
            scanf("%d%d",&t[i],&c[i]);
            for(int j=1;j<=t[i];j++)
                scanf("%d",&q[i][j]);
        }
        
        for(int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]),p[i]=i;
        
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            _e[++m]=(edge){i,j,dist(i,j)};
        sort(_e+1,_e+m+1);
        
        ll ans=0;
        for(int i=1;i<=m;i++){
            int x=find(_e[i].u),y=find(_e[i].v);
            if(x!=y){
                e[++cnt]=_e[i];
                ans+=_e[i].w;
                p[x]=y;
            }
        }
        
        for(int S=0;S<(1<<r);S++){
            ll ansx=0;
            for(int i=1;i<=n;i++) p[i]=i;
            
            for(int i=0;i<r;i++)
                if(S&(1<<i)){
                    ansx+=c[i];
                    for(int j=2;j<=t[i];j++)
                        p[find(q[i][j-1])]=find(q[i][j]);
                }
            ansx+=solve();
            ans=min(ans,ansx);
        }
        printf("%lld\n",ans);
        if(T) printf("\n");
    }
    return 0;
}