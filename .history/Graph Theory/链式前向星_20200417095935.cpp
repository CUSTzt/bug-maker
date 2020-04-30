const int N = 3e5 + 10;
struct Edge {
    int nex, to, w;
} edge[N << 1];
int head[N], tot;
void add_edge(int u, int v, int w) {
    edge[++tot].nex = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}

int dis[N], size[N], n, k, vis[N];
void dfs(int u, int fa) {
    dis[u] = dis[fa] + 1;
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].nex) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        size[u] += size[v];
    }
}