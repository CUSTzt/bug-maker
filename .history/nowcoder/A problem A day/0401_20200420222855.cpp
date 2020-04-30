// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

// const int N = 1e6+100;
const int N = 3e5 + 10;
struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot;
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}

int dis[N], si[N], n, s, m, vis[N], f[N], deg[N];
void dfs(int u, int fa) {
    if(deg[u] == 1 && u != s)return;
    f[u] = 0;
    for(ll i = head[u]; i; i = edge[i].nxt){
        if(edge[i].to != fa){
            dfs(edge[i].to, fa);
            f[u] += min(f[edge[i].to], edge[i].w);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y , z;
        cin >> x >> y >> z;
        deg[x]++, deg[y]++, add_edge(x, y , z), add_edge(y , x , z); 
    }
    memset(f, 0x3f, sizeof f);
    dfs(s,0);
    cout << f[s] << endl;
    return 0;
}