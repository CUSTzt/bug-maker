// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>

#include <cstdio>
#include <iostream>
#include <vector>
#define int long long
using namespace std;
#define maxn 400010

struct Node {
    int v, w;
    Node(int v_, int w_) { v = v_, w = w_; }
};
vector<Node> g[maxn];

int father[maxn];
int dis[maxn];
int dep[maxn];
void dfs(int u, int fa, int deep) {
    father[u] = fa;
    dep[u] = deep;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i].v;
        if (v == fa) continue;  //

        dis[v] = dis[u] + g[u][i].w;
        dfs(v, u, deep + 1);
    }
}

int p[maxn][30];
void Init_LCA() {
    for (int j = 0; (1 << j) <= n; ++j)
        for (int i = 1; i <= n; ++i) p[i][j] = -1;
    for (int i = 1; i <= n; ++i) p[i][0] = father[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i <= n; ++i)
            if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int i, lg;
    for (lg = 0; (1 << lg) <= dep[x]; ++lg)
        ;
    --lg;
    /// 使x往上走直到和y在同一水平线上；
    for (i = lg; i >= 0; --i)
        if (dep[x] - (1 << i) >= dep[y]) x = p[x][i];
    if (x == y) return x;
    /// 此时x，y在同一水平线上，使x，y同时以相同的速度(2^j)往上走；
    for (i = lg; i >= 0; --i)
        if (p[x][i] != -1 && p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
    return father[x];
}

int n, m;
set<int> s;

int32_t main() {
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        g[x].push_back(Node(y, w));
        g[y].push_back(Node(x, w));
    }

    dis[1] = 0;
    dfs(1, -1, 0);

    Init_LCA();
    

}
