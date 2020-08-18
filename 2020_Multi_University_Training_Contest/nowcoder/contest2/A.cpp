#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define read(x) scanf("%d",&x)
typedef long long ll;
typedef double dl;
using namespace std;
 
const int N=3e5+7;
const int INF=0x3f3f3f3f;
 
int n,m;
 
int deg[N];
int fa[N];
int vis[N];
int link[N];
int ls[N],tot=0;
vector<int> G[N];
 
void dfs(int x){
    vis[x]=1;
    if (deg[x]==1){
        ls[++tot]=x;
        return;
    }
    for(auto to:G[x]){
        if (vis[to]==1) continue;
        dfs(to);
    }
    return;
}
 
void out(int a,int b){
    if (a>b) swap(a,b);
    printf("%d %d\n",a,b);
}
 
void solve(){
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        deg[u]++;
        deg[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if (deg[i]!=1){
            dfs(i);
            break;
        }
    }
    memset(vis,0,sizeof(vis));
    m=(tot+1)/2;
    printf("%d\n",m);
    for(int i=1,j=m+1;i<=tot/2;i++,j+=3){
        if (j>tot){
            j=m+1;
            while(vis[j]==1){
                j++;
            }
        }
//      cout<<i<<" "<<j<<endl;
        vis[i]=vis[j]=1;
        out(ls[i],ls[j]);
    }
    if (tot%2==1) out(ls[1],ls[m]);
}
 
int main(){
        solve();
}
