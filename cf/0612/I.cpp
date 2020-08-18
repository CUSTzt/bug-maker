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
const ll inf = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5+10;

int n,P;

vector<pii> g[N];;
ll sum[N],dp[N],ans=0;

ll getDP(int i,int j){
    return dp[j]+P+(sum[i]-sum[j])*(sum[i]-sum[j]);
}

ll getUP(int j,int k){
    return dp[j]+sum[j]*sum[j]-(dp[k]+sum[k]*sum[k]);
}

ll getDOWN(int j,int k){
    return 2*(sum[j]-sum[k]);
}

void dfssum(int x,int fa){
    for(auto it:g[x]){
        int v=it.fi,w=it.se;
        if(v==fa)continue;
        sum[v]=sum[x]+w;
        dfssum(v,x);
    }
}

int q[N],head=0,tail=0;

void dfs(int x,int fa){
    if(sz(g[x])==1 && g[x][0].fi==fa){
        ans=max(ans,dp[x]);
        return ;
    }
    for(auto it:g[x]){
        int v=it.fi;
        if(v==fa)continue;
        int tp1=head,tp2=tail;
        while(head+1<tail && getUP(q[head+1],q[head])<=sum[v]*getDOWN(q[head+1],q[head]))
            head++;
        dp[v]=getDP(v,q[head]);
        while(head+1<tail && getUP(v,q[tail-1])*getDOWN(q[tail-1],q[tail-2])<=getUP(q[tail-1],q[tail-2])*getDOWN(v,q[tail-1]))
            tail--;
        q[tail++]=v;
        dfs(v,x);
        head=tp1,tail=tp2;
    }
}

void solve(){
    ans=0;
    cin>>n>>P;
    if(n==1){
        cout<<0<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    memset(sum,0,sizeof sum);
    dfssum(1,0);
    head=tail=0;
    q[tail++]=1;
    dp[1]=0;
    dfs(1,0);
    cout<<ans-P<<endl;
}

int main(){
    IOS;
    int _;cin>>_;
    while(_--)solve();
    return 0;
}