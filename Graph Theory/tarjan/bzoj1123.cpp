// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 10;
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

int dfn[N], low[N], stack[N], sz[N], ans[N];
int n, m, num, root;
bool cut[N];
void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    sz[x] = 1;
    int flag = 0, sum = 0;
    for (int i = head[x]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        if (!dfn[y]) {
            tarjan(y);
            sz[x] += sz[y];
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                flag++;
                ans[x] += (ll)sz[y] * (n - sz[y]);
                sum += sz[y];
                if (x != root || flag > 1) cut[x] = 1;
            }
        } else {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (cut[x])
        ans[x] += (ll)(n - sum - 1) * (sum + 1) + (n - 1);
    else
        ans[x] = 2 * (n - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int x, y;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        if (x == y) continue;
        add_edge(x, y, 1);
        add_edge(y, x, 1);
    }
    tarjan(1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}