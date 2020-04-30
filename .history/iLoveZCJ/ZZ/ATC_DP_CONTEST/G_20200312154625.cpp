// She is Pretty pretty!
// DAG上dp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , m , x , y ,dp[N], deg[N];
vector<int > G[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m ; i++){
        cin >> x >> y;
        deg[y]++;G[x].pb(y);
    }
    queue<int > q ;
    for(int i = 1; i <= n; i++){
        if(!deg[i])q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << "now === " << now << endl;
        for(auto it : G[now]){
            dp[G[now][it]] = max(dp[now]+1, dp[G[now][it]]);
            deg[G[now][it]]--;
            if(!deg[G[now][it]])q.push(G[now][it]);
            cout << "it "== <<  it << endl;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(dp[i], ans);
    }cout << ans << endl;
    return 0;
}