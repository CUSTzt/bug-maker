#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
int a[N], b[N], n2, hd[N], ne, n, m, nq, fa[N][20], dep[N], siz[N], fa2[N],
    rt[N], ls[N * 100], rs[N * 100], val[N * 100], tot, vis[N];
struct E {
    int v, nxt;
} e[N << 1];
void addedge(int u, int v) { e[ne] = {v, hd[u]}, hd[u] = ne++; }
int fd(int x) { return ~fa2[x] ? fa2[x] = fd(fa2[x]) : x; }
int mgg(int x, int y) {
    int fx = fd(x), fy = fd(y);
    if (fx == fy) return 0;
    fa2[fx] = fy, siz[fy] += siz[fx];
    return 1;
}
#define mid ((l + r) >> 1)
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0 && dep[u] > dep[v]; --i)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; --i)
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
void upd(int& u, int v, int x, int l = 1, int r = n2) {
    if (!u) u = ++tot;
    val[u] = val[v] + 1;
    if (l == r) return;
    if (x <= mid)
        upd(ls[u], ls[v], x, l, mid), rs[u] = rs[v];
    else
        upd(rs[u], rs[v], x, mid + 1, r), ls[u] = ls[v];
}
int qry(int u, int v, int w1, int w2, int k, int l = 1, int r = n2) {
    if (l == r) return l;
    int cnt = val[ls[u]] + val[ls[v]] - val[ls[w1]] - val[ls[w2]];
    return k <= cnt ? qry(ls[u], ls[v], ls[w1], ls[w2], k, l, mid)
                    : qry(rs[u], rs[v], rs[w1], rs[w2], k - cnt, mid + 1, r);
}
void dfs(int u, int f, int d, int flag) {
    if (flag && vis[u]) return;
    vis[u] = 1;
    fa[u][0] = f, dep[u] = d, rt[u] = 0, upd(rt[u], rt[f], a[u]);
    for (int i = 1; i < 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = hd[u]; ~i; i = e[i].nxt) {
        int v = e[i].v;
        if (v == f) continue;
        dfs(v, u, d + 1, flag);
    }
}
void mg(int u, int v) {
    if (siz[fd(u)] > siz[fd(v)]) swap(u, v);
    addedge(u, v), addedge(v, u), mgg(u, v), dfs(u, v, dep[v] + 1, 0);
}
int main() {
    scanf("%*d");
    memset(hd, -1, sizeof hd), ne = 0;
    memset(fa2, -1, sizeof fa2);
    scanf("%d%d%d", &n, &m, &nq);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) b[i - 1] = a[i];
    sort(b, b + n), n2 = unique(b, b + n) - b;
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(b, b + n2, a[i]) - b + 1;
    for (int i = 1; i <= n; ++i) siz[i] = 1;
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v), addedge(v, u), mgg(u, v);
    }
    for (int i = 1; i <= n; ++i) dfs(i, 0, 1, 1);
    for (int last = 0; nq--;) {
        char ch;
        int u, v, k;
        scanf(" %c", &ch);
        if (ch == 'Q') {
            scanf("%d%d%d", &u, &v, &k), u ^= last, v ^= last, k ^= last;
            int w = lca(u, v),
                ans = b[qry(rt[u], rt[v], rt[w], rt[fa[w][0]], k) - 1];
            printf("%d\n", ans), last = ans;
        } else {
            scanf("%d%d", &u, &v), u ^= last, v ^= last;
            mg(u, v);
        }
    }
    return 0;
}