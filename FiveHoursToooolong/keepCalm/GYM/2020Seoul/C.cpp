#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt","w",stdout);
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N=1e5+10;
VI g[N];
int vis[N],cnt=0;

int dfs(int x,int fa){
    int f=0;
    for(auto it:g[x]){
        if(it!=fa){
            if(dfs(it,x))f=1;
        }
    }
    if(vis[x])f=1;
    if(f) cnt++;
    return f;
}
int main(){
//    IN;
    IOS;
    int n,k;cin>>n>>k;
    for(int i=0,x,y,z;i<n-1;i++){
        cin>>x>>y>>z;
        g[x].pb(y),g[y].pb(x);
    }
    int rt=0;
    for(int i=1,x;i<=k;i++){
        cin>>x;
        rt=x;
        vis[x]++;
    }
    dfs(rt,0);
    cout<<cnt<<endl;
    return 0;
}