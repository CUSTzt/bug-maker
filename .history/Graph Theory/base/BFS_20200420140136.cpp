#include<bits/stdc++.h>
using names
const int N = 1e6 + 100;
int head[N], vis[N], d[N], p[N];
void bfs(int u) {
    while (!Q.empty()) Q.pop();
    Q.push(u);
    vis[u] = 1;
    d[u] = 0;
    p[u] = -1;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = e[i].x) {
            if (!vis[e[i].t]) {
                Q.push(e[i].t);
                vis[e[i].t] = 1;
                d[e[i].t] = d[u] + 1;
                p[e[i].t] = u;
            }
        }
    }
}
void restore(int x) {
    vector<int> res;
    for (int v = x; v != -1; v = p[v]) {
        res.push_back(v);
    }
    std::reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) printf("%d", res[i]);
    puts("");
}