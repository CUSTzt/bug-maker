#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-8;
const int N=2e5+10,M=N<<2,mod=201314;
int n,m,k;
int a[N];
vector<int>G[N];
struct node{
    int d,dd;
}s[N];
bool vis[N];
void bfs(){
    queue<int>q;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        //cout<<' '<<x<<' '<<s[x].d<<endl;
        q.pop();
        for(int i=0;i<G[x].size();i++){
            int &y=G[x][i];
            if(vis[y])continue;
            s[y].d=s[x].d+1;
            q.push(y);
            vis[y]=1;
        }
    }
    return;
}
void bfs2(){
    queue<int>q;
    memset(vis,0,sizeof(vis));
    vis[n]=1;
    q.push(n);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<G[x].size();i++){
            int &y=G[x][i];
            if(vis[y])continue;
            s[y].dd=s[x].dd+1;
            q.push(y);
            vis[y]=1;
        }
    }
    return;
}
int mx[N];
struct kkk{
    int d,dd;
    bool operator<(const kkk &t)const{
        return d<t.d;
    }
}b[N];
int ss[M];
void update(int loc,int x,int k,int l,int r){
    if(l==r){
        ss[x]=max(ss[x],k);
        return;
    }
    int mid=l+r>>1;
    if(loc<=mid)update(loc,x<<1,k,l,mid);
    else update(loc,x<<1|1,k,mid+1,r);
    ss[x]=max(ss[x<<1],ss[x<<1|1]);
}
int query(int a,int b,int x,int l,int r){
    if(a==l&&b==r)return ss[x];
    int mid=l+r>>1;
    int ls=x<<1,rs=x<<1|1;
    if(b<=mid)return query(a,b,ls,l,mid);
    else if(a>mid)return query(a,b,rs,mid+1,r);
    else return max(query(a,mid,ls,l,mid),query(mid+1,b,rs,mid+1,r));
}
bool check(int x){
    for(int i=0;i<M;i++)ss[i]=-INF;
    for(int i=1;i<=k;i++){
        int l=max(0,x-b[i].d);
        //cout<<l<<' '<<query(l,n,1,0,n)<<' '<<b[i].dd<<endl;
        if(query(l,n,1,0,n)+b[i].dd+1>=x)return 1;
        update(b[i].dd,1,b[i].d,0,n);
    }
    return 0;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)s[i].d=s[i].dd=0;
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1,u,v;i<=m;i++){
        scanf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    bfs();
    bfs2();
    int ans=0;
    int l=1,r=s[n].d;
    for(int i=1;i<=k;i++){
        b[i].d=s[a[i]].d;
        b[i].dd=s[a[i]].dd;
        //cout<<b[i].d<<' '<<b[i].dd<<endl;
    }
    sort(b+1,b+1+k);
    while(l<=r){
        int mid=l+r>>1;
        //cout<<l<<' '<<r<<endl;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}