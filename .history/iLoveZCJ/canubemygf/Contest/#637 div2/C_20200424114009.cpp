#include <bits/stdc++.h>
#define MAXN 100005  // 这里注意一下范围
#define MAXLOGN 22
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, q;
int st[MAXLOGN + 1][4 * MAXN];
struct node {
    int nxt, w;
    node(int _nxt, int _w) { nxt = _nxt, w = _w; }
};

vector<node> G[MAXN];
int vs[MAXN * 2 - 1];
int depth[MAXN * 2 - 1];
int id[MAXN];
int DIS[MAXN];
void dfs(int v, int p, int d, int &k) {
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for (int i = 0; i < (int)G[v].size(); i++) {
        if (G[v][i].nxt != p) {
            DIS[G[v][i].nxt] = DIS[v]+G[v][i].w;
            dfs(G[v][i].nxt, v, d + 1, k);
            vs[k] = v;
            depth[k++] = d;
        }
    }
}
int getMin(int x, int y) { return depth[x] < depth[y] ? x : y; }

void rmq_init(int n) {
    for (int i = 1; i <= n; ++i) st[0][i] = i;
    for (int i = 1; 1 << i < n; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            st[i][j] = getMin(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
void init(int V) {
    int k = 0;  // 默认是1为根
    dfs(1, 0, 0, k);
    rmq_init(V * 2 - 1);
}
int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return getMin(st[k][l], st[k][r - (1 << k) + 1]);
}
int lca(int u, int v) {
    if (u == v) return u;
    return vs[query(min(id[u], id[v]), max(id[u], id[v]))];
}
int dis(int u, int v) {
    return depth[id[u]] + depth[id[v]] - 2 * depth[id[lca(u, v)]];
}
int main() {
    //注意maxn 和maxlog范围，注意一下是以谁为根
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tp;
    cin >> tp;
    while (tp--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n + 10; i++) G[i].clear();
        for (int i = 1; i < n; i++) {
            int x, y , z;
            cin >> x >> y >> z;
            G[x].push_back(node(y,z));
            G[y].push_back(node(x,z));
        }
        dis[]
    }
    return 0;
}