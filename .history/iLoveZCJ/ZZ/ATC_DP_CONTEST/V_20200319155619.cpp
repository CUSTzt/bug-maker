// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
vector<ll > G[N], G1[N];
ll dp[N], dp1[N], mod, pre[N], suf[N];
void dfs(int u , int fa){
    dp[u] = 1;
    for(auto v : G[u]){
        if(v != fa){
            dfs(v , u);
            G1[u].pb(v);
            dp[u] = dp[u] * (dp[v] + 1) % mod;
        }
    }
}
void dfs1(int u){
    int si = (int ) G1[u].size();
    pre[0] = 1;
    suf[si+1] = 1;
    for(int i = 0; i < si ; i++){
        int v = G1[u][i];
        pre[i+1] = pre[i] * (dp[v] + 1) % mod;
    }
    for(int i = si - 1; i >= 0; --i){
        int v = G1[u][i];
        suf[i+1] =suf[i+2] * (dp[v] + 1) % mod;
    }
    for(int i = 0; i < si ; i++){
        int v = G1[u][i];
        dp1[v] = pre[i] * suf[i+2] % mod *(dp1[u] + 1) % mod;
    }
    for(int i = 0; i < si ; i++){
        dfs1(G1[u][i]);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n >> mod;
    for()
    return 0;
}