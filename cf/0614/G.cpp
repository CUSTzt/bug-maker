#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;


const int MAXN = 1e4+10;
const int MAXM = 1e5+10;
struct Edge{
    int to,next,cap,flow;
    double cost;
}e[MAXM];
int head[MAXN],tol;
int pre[MAXN];
double dis[MAXN];
bool vis[MAXN];
int N;
void init(int n){
    N=n;
    tol=0;
    memset(head,-1,sizeof head);
}
void addedge(int u,int v,int cap,double cost){
    e[tol].to=v;
    e[tol].cap=cap;
    e[tol].cost=cost;
    e[tol].flow=0;
    e[tol].next=head[u];
    head[u]=tol++;
    e[tol].to=u;
    e[tol].cap=0;
    e[tol].cost=-cost;
    e[tol].flow=0;
    e[tol].next=head[v];
    head[v]=tol++;
}

bool spfa(int s,int t){
    queue<int> q;
    for(int i=0;i<N;i++){
        dis[i]=inf;
        vis[i]=false;
        pre[i]=-1;
    }
    dis[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];~i;i=e[i].next){
            int v=e[i].to;
            if(e[i].cap>e[i].flow&&dis[v]>dis[u]+e[i].cost){
                dis[v]=dis[u]+e[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t]==-1)return 0;
    return 1;
}

int minCostMaxflow(int s,int t,double &cost){
    int flow=0;
    cost=0;
    while(spfa(s,t)){
        int Min=inf;
        for(int i=pre[t];~i;i=pre[e[i^1].to]){
            if(Min>e[i].cap-e[i].flow)
                Min=e[i].cap-e[i].flow;
        }
        for(int i=pre[t];~i;i=pre[e[i^1].to]){
            e[i].flow+=Min;
            e[i^1].flow-=Min;
            cost+=e[i].cost*Min;
        }
        flow+=Min;
    }
    return flow;
}

int from[110];

int main(){
    IOS;
    int n;cin>>n;
    init(4*n+10);
    int st=0,ed=4*n+1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        int x;cin>>x;
        int l=i,r=j+2*n;
        addedge(i+n,r,1,-log(x));
    }
    for(int i=1;i<=n;i++){
        addedge(st,i,1,0);
        addedge(i+3*n,ed,1,0);
        addedge(i,i+n,1,0);
        addedge(i+2*n,i+3*n,1,0);
    }
    double co;
    minCostMaxflow(st,ed,co);
    for(int i=1;i<=n;i++) {
        int lef=i+n;
        for(int j=head[lef];~j;j=e[j].next){
            if(e[j].flow && e[j].to>2*n)from[e[j].to-2*n]=i;
        }
    }
    for(int i=1;i<=n;i++)cout<<from[i]<<' ';
    return 0;
}
/*
3
1 15 37
42 8 25
77 2 1

2
15 1
33 42

 */