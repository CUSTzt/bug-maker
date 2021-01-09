#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-6
#define LL long long
#define pii pair<int, int>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
//最大流
// Dinic算法求最大流，一般效率很高
// s源点，t汇点，g，e全局变量，表示存边的邻接表
const int INF = 1000000000;
const int MAXN = 4000, MAXM = 500000;  //最大的点数和边数
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, -1, 0, 1};
struct Edge {
    int to, next, cap;
} edge[MAXM * 2];
int n, s, t;
int head[MAXN], tot;
void addedge(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].cap = w;
    edge[tot].next = head[u];
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].cap = 0;
    edge[tot].next = head[v];
    head[v] = tot++;
}
void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}
queue<int> q;
bool vis[MAXN];
int dist[MAXN];
void bfs() {
    memset(dist, 0, sizeof(dist));
    while (!q.empty()) q.pop();
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (!edge[i].cap || vis[edge[i].to]) continue;
            q.push(edge[i].to);
            vis[edge[i].to] = 1;
            dist[edge[i].to] = dist[u] + 1;
        }
    }
}
int dfs(int u, int a) {
    if (u == t) return a;
    int ret = 0;
    for (int i = head[u]; a && i != -1; i = edge[i].next) {
        if (edge[i].cap && dist[u] + 1 == dist[edge[i].to]) {
            int tmp = dfs(edge[i].to, min(a, edge[i].cap));
            edge[i].cap -= tmp;
            edge[i ^ 1].cap += tmp;
            a -= tmp;
            ret += tmp;
        }
    }
    return ret;
}
int maxflow() {
    int ret = 0;
    while (true) {
        memset(vis, 0, sizeof(vis));
        bfs();
        if (!vis[t]) return ret;
        ret += dfs(s, INF);
    }
}
char G[50][50];
int id[50][50];
int main() {
    int row, col;
    while (cin >> row >> col) {
        init();
        int cntW = 0, cntI = 0, cntN = 0;
        for (int i = 1; i <= row; i++) {
            scanf("%s", G[i] + 1);
            for (int j = 1; j <= col; j++) {
                if (G[i][j] == 'W')
                    cntW++;
                else if (G[i][j] == 'I')
                    cntI++;
                else
                    cntN++;
            }
        }
        int tmp1 = 0, tmp2 = 0, tmp3 = 0;
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++) {
                if (G[i][j] == 'W')
                    id[i][j] = ++tmp1;
                else if (G[i][j] == 'I')
                    id[i][j] = ++tmp2;
                else
                    id[i][j] = ++tmp3;
            }
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (G[i][j] == 'W') {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + DX[k], ny = j + DY[k];
                        if (nx < 1 || nx > row || ny < 1 || ny > col) continue;
                        if (G[nx][ny] == 'I')
                            addedge(1 + id[i][j], 1 + cntW + id[nx][ny], 1);
                    }
                } else if (G[i][j] == 'N') {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + DX[k], ny = j + DY[k];
                        if (nx < 1 || nx > row || ny < 1 || ny > col) continue;
                        if (G[nx][ny] == 'I')
                            addedge(1 + cntW + cntI + id[nx][ny],
                                    1 + cntW + cntI + cntI + id[i][j], 1);
                    }
                }
            }
        }
        n = cntW + 2 * cntI + cntN + 2;
        s = 1, t = n;
        for (int i = 1; i <= cntI; i++)
            addedge(1 + cntW + i, 1 + cntW + cntI + i, 1);
        for (int i = 1; i <= cntW; i++) addedge(1, i + 1, 1);
        for (int i = 1; i <= cntN; i++)
            addedge(1 + cntW + cntI + cntI + i, n, 1);
        int ans = maxflow();
        cout << ans << endl;
    }
    return 0;
}
