#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10;
int head[N], to[N << 1], nxt[N << 1], col[N << 1], nEdge;
int bg[N], ed[N], cntcol[N], nnode;
int c[N];
vector<int> ans;
int lowbit(int x) { return x & -x; }
void add(int u, int x) {
    while (u < N) {
        c[u] += x;
        u += lowbit(u);
    }
}
int query(int u) {
    int ret = 0;
    while (u) {
        ret += c[u];
        u -= lowbit(u);
    }
    return ret;
}
void AddEdge(int u, int v, int c) {
    nxt[nEdge] = head[u], to[nEdge] = v, col[nEdge] = c, head[u] = nEdge++;
}
void dfs1(int u, int fa) {
    bg[u] = ed[u] = ++nnode;
    for (int e = head[u]; ~e; e = nxt[e]) {
        int v = to[e];
        if (v == fa) continue;
        dfs1(v, u);
        ed[u] = ed[v];
    }
}
void dfs2(int u, int fa, int c) {
    for (int e = head[u]; ~e; e = nxt[e]) cntcol[col[e]]++;
    for (int e = head[u]; ~e; e = nxt[e]) {
        if (cntcol[col[e]] > 1) {
            int v = to[e];
            add(bg[v], 1), add(ed[v] + 1, -1);
            if (v == fa)
                add(1, 1), add(bg[v] + 1, -1), add(ed[v] + 1, 1),
                    add(bg[u], -1), add(ed[u] + 1, 1);
        }
    }
    for (int e = head[u]; ~e; e = nxt[e]) cntcol[col[e]] = 0;
    for (int e = head[u]; ~e; e = nxt[e]) {
        int v = to[e];
        if (v == fa) continue;
        dfs2(v, u, col[e]);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    memset(head, -1, sizeof head);
    memset(cntcol, 0, sizeof cntcol);
    nEdge = nnode = 0;
    int n; scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        AddEdge(u, v, c); AddEdge(v, u, c);
    }
    dfs1(1, -1); dfs2(1, -1, -1);
    for (int i = 1; i <= n; ++i)
        if (query(bg[i]) == 0) ans.push_back(i);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);
    return 0;
}