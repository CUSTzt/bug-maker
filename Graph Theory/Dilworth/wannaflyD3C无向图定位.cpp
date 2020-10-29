//https://ac.nowcoder.com/acm/contest/4114/C

#include<bits/stdc++.h>

using namespace std;
constexpr int maxn = (1 << 18);
int n , m, a[maxn], g[maxn][maxn], ans, u , v;
void dfs(){
    
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    ans = n+1;
    dfs(1, 0);
    cout << ans-1 << endl;
}