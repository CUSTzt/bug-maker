
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
int pos[N];
bool cmp(int x, int y) { return dis[x] - size[x] > dis[y] - size[y]; }
signed main() {
    ios;
    cin >> n >> k;
    rep(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    dfs(1, 0);
    rep(i, 1, n) pos[i] = i;
    sort(pos + 1, pos + 1 + n, cmp);
    ll ans = 0;
    rep(i, 1, k) ans += dis[pos[i]] - size[pos[i]];
    cout << ans << '\n';
    return 0;
}
