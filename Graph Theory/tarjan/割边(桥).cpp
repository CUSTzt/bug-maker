// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot;
int dfn[N], low[N], n, m, num;
bool bridge[N];
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}
void tarjan(int x, int in_edge) {
    dfn[x] = low[x] = ++num;
    int flag = 0;
    for (int i = head[x]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);

            if (low[y] > dfn[x]) bridge[i] = bridge[i ^ 1] = 1;
        } else if (i != (in_edge ^ 1)) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}

int main() { // 正确性暂时还没验证
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y, 1);
        add_edge(y, x, 1);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i, 0);
    }
    for (int i = 2; i < tot; i += 2) {
        if (bridge[i]) {
            cout << edge[i ^ 1].to << " " << edge[i].to << endl;
        }
    }
    return 0;
}