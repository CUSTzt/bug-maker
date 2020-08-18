#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 50;
vector<int> G[maxn];
ll p[maxn];
ll h[maxn];
int n;
bool flag = true;
int dfs(int v, int fa){
    ll sum = 0;
    for(auto &u : G[v]){
        if(u != fa){
            sum += dfs(u, v);
            p[v] += p[u];
        }
    }
    if((h[v] + p[v]) % 2 ||  h[v] > p[v] || h[v] < -p[v]) flag = false;
    ll g = (h[v] + p[v]) / 2;
    if(g < sum) flag = false;
    return g;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        ll m;
        cin >> n >> m;
        flag = true;
        for(int i = 0;i <= n;i++) G[i].clear();
        for(int i = 1;i <= n;i++) cin >> p[i];
        for(int i = 1;i <= n;i++) cin >> h[i];
        for(int i = 1;i <= n - 1;i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, 1);
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
