// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int INF = 1e18;
const int N = 1e6 + 100;
struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot, nxt[N];
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
int fa[N * 2], sum, vis[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int d[N], f[N][25], g[N][25][3];
int calc(int u, int i) {
    int v = f[u][i - 1];
    if (g[u][i - 1][0] == g[v][i - 1][0]) {
        return max(g[u][i - 1][1], g[v][i - 1][1]);

    } else if (g[u][i - 1][0] > g[v][i - 1][0]) {
        return max(g[u][i - 1][1], g[v][i - 1][0]);
    } else {
        return max(g[u][i - 1][0], g[v][i - 1][1]);
    }
}
void dfs(int u, int fa) {
    d[u] = d[fa] + 1;
    for (int i = 1; i <= 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
        g[u][i][0] = max(g[u][i - 1][0], g[f[u][i - 1]][i - 1][0]);
        g[u][i][1] = calc(u, i);
    }
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        int w = edge[i].w;
        if (v == fa) continue;
        f[v][0] = u;
        g[v][0][0] = w;
        g[v][0][1] = -INF;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (d[f[y][i]] >= d[x]) y = f[y][i];
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {  // 没有＝爆炸了。
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
int querymax(int x, int y, int z) {
    int ans = -INF;
    for (int i = 20; i >= 0; i--) {
        if (d[f[x][i]] < d[y]) continue;
        ans = z == g[x][i][0] ? max(ans, g[x][i][1]) : max(ans, g[x][i][0]);
        x = f[x][i];
    }
    return ans;
}

int n, m, ans = INF;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < N * 3 / 2; i++) fa[i] = i;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        int fx = find(e[i].u), fy = find(e[i].v);
        if (fx == fy) continue;
        add_edge(e[i].u, e[i].v, e[i].w);
        add_edge(e[i].v, e[i].u, e[i].w);
        fa[fx] = fy;
        vis[i] = 1;
        sum += 1ll * e[i].w;
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        if (vis[i]) continue;
        int lcaa = lca(e[i].u, e[i].v);
        int val =
            max(querymax(e[i].u, lcaa, e[i].w), querymax(e[i].v, lcaa, e[i].w));
        ans = min(ans, sum - val + e[i].w);
    }
    cout << ans << endl;
    return 0;
}