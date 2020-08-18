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

const int N = 1e5+10;
VI g[N];
int d[N],depth[N];
VI res;

void dfs(int x,int dep){
    depth[x]=dep;
    if(!sz(g[x])){
        d[x]=dep;
        return;
    }
    for(auto it:g[x]){
         dfs(it,dep+1);
         d[x]=max(d[x],d[it]);
    }
}

void dfs2(int x){
    if(!sz(g[x]))return;
    VI r;
    for(auto it:g[x])r.pb(d[it]);
    sort(all(r));
    for(int i=0;i<sz(r)-1;i++)res.pb(r[i]-depth[x]);
    if(x==1)res.pb(r.back());
    for(auto it:g[x])dfs2(it);
}

int main(){
    IOS;
    ll n,k;cin>>n>>k;
    for(int i=2,x;i<=n;i++){
        cin>>x;
        g[x].pb(i);
    }
    dfs(1,1);
    dfs2(1);
    if(k>=sz(res))cout<<n<<endl;
    else{
        int sum=0;
        sort(all(res));
        while(k){
            sum+=res.back();
            res.pop_back();
            k--;
        }
        cout<<sum<<endl;
    }
    return 0;
}
/*
10 3
1 1 2 2 3 3 4 4 5
*/