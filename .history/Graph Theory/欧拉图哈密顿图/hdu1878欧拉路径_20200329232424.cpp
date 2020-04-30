//判断存不存在欧拉回路
// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

namespace UndirectedGraph {
    const int N = 1100,M = 1000*1000;
int n, m, i, x, y, d[N], g[N], v[M << 1], w[M << 1], vis[M << 1], nxt[M << 1],
    ed;
int ans[M], cnt;
void add(int x, int y, int z) {
    d[x]++;
    v[++ed] = y;
    w[ed] = z;
    nxt[ed] = g[x];
    g[x] = ed;
}
void dfs(int x) {
    for (int& i = g[x]; i;) {
        if (vis[i]) {
            i = nxt[i];
            continue;
        }
        vis[i] = vis[i ^ 1] = 1;
        int j = w[i];
        dfs(v[i]);
        ans[++cnt] = j;
    }
}
void solve() {
    scanf("%d %d", &n, &m);
    for (i = ed = 1; i <= m; i++)
        scanf("%d %d", &x, &y), add(x, y, i), add(y, x,-i); 
    for (i = 1; i <= n; i++)
        if (d[i] & 1) {
            puts("0");
            return;
        }
    for (i = 1; i <= n; i++)
        if (g[i]) {
            dfs(i);
            break;
        }
    for (i = 1; i <= n; i++)
        if (g[i]) {
            puts("0");
            return;
        }
    puts("1");
    
}
}  // namespace UndirectedGraph
int main(){
    UndirectedGraph::solve();
}