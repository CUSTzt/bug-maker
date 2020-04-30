// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
const int N = 3e5 + 10;
struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot, nxt[maxn];
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}
struct Node {
    int u, v, w;
} e[N];
int cmp(Node a, Node b) { return a.w < b.w; }

int fa[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int d[N], f[N][25], g[N][25][3];
int calc(int u, int i) {
    int v = f[u][i - 1];
    if (g[u][i - 1][0] == g[v][i - 1][0]) {
        {
            return max(g[u][i - 1][1], g[v][i - 1][1]);
        }
    } else if (g[u][i - 1][0] > g[v][i - 1][0]) {
        return max(g[u][i - 1][1], g[v][i - 1][0]);
    } else {
        return max(g[u][i - 1][0], g[v][i - 1][1]);
    }
}
void dfs(int u , int fa){
    d[u] = d[fa] + 1;
    for(int i = 1; i <= 20;i++){
        f[u][i] = f[f[u][i-1]][i-1];
        g[u][i][0] = max(g[u][i - 1][0], g[f[u][i - 1]][i - 1][0]);
        g[u][i][1] = calc(u, i);
    }
    for(int i = head[u]; i ; )
}

int lca(int x, int y){
    if(d[x] > d[y])swap(x , y);
    for(int i = 20; i ; i--){
        if(d[f[y][i]] >= d[x])y = f[y][i];
    }
    if(x == y) return x;
    for(int i = 20; i >= 0; i--){
        if(f[x][i] != f[y][i]) x = f[x][i] , y = f[y][i];
    }
    return f[x][0];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}