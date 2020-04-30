// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define maxn 1000010

int n;
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
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    int T, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
        int x, y, w;
        x = read(), y = read();
        // scanf("%d%d", &x, &y);
        g[x].emplace_back _back(Node(y, 1));
        g[y].push_back(Node(x, 1));
    }
    dis[1] = 0;
    dfs(s, -1, 0);
    Init_LCA();
    while (m--) {
        int x, y;
        x = read(), y = read();
        //scanf("%d%d", &x, &y);
        // printf("%d\n", LCA(x, y));
        print(LCA(x,y));puts("");
    }
}
