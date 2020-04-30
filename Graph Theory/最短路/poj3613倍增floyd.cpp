#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 205, M = 105;
struct Edge{
    int u, v, w;
}e[M];
int m, n, s, t, adj[N], tot, d[N][N][20], f[N], g[N];
int L;

int inline get(int x) {
    return lower_bound(adj + 1, adj + 1 + tot, x) - adj;
}
int main(){
    memset(d, 0x3f, sizeof d);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    L = log2(n);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &e[i].w, &e[i].u, &e[i].v);
        adj[++tot] = e[i].u;
        adj[++tot] = e[i].v;
    }
    sort(adj + 1, adj + 1 + tot);
    tot = unique(adj + 1, adj + 1 + tot) - adj - 1;
    for (int i = 1; i <= m; i++) {
        int u = get(e[i].u), v = get(e[i].v), w = e[i].w;
        d[u][v][0] = d[v][u][0] = min(d[u][v][0], w);
    }
    s = get(s), t = get(t);

    for (int c = 1; c <= L; c++) {
        for (int i = 1; i <= tot; i++) {
            for (int j = 1; j <= tot; j++) {
                for (int k = 1; k <= tot; k++) {
                    d[i][j][c] = min(d[i][j][c], d[i][k][c - 1] + d[k][j][c - 1]);
                }
            }
        }
    }

    memset(g, 0x3f, sizeof g);
    g[s] = 0;
    for (int c = 0; c <= L; c++) {
        if(n >> c & 1) {
            memset(f, 0x3f, sizeof f);
            for (int i = 1; i <= tot; i++) 
                for (int j = 1; j <= tot; j++)
                    f[i] = min(f[i], g[j] + d[j][i][c]);
            memcpy(g, f, sizeof g);
        }
    }
    printf("%d\n", f[t]);
    return 0;
}
