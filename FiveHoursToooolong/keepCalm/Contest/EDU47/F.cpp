#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define re register
#define LL long long
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
const int maxn = 1000005;
inline int read() {
    char c = getchar();
    int x = 0;
    while (c < '0' || x > '9') c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + c - 48, c = getchar();
    return x;
}
struct E {
    int v, nxt;
} e[maxn << 1];
int head[maxn], deep[maxn], len[maxn], son[maxn];
int n, num, tax[maxn], *id = tax, *f[maxn], ans[maxn];
inline void add(int x, int y) {
    e[++num].v = y;
    e[num].nxt = head[x];
    head[x] = num;
}
void dfs1(int x) {
    int maxx = -1;
    for (re int i = head[x]; i; i = e[i].nxt) {
        if (deep[e[i].v]) continue;
        deep[e[i].v] = deep[x] + 1;
        dfs1(e[i].v);
        if (len[e[i].v] > maxx) maxx = len[e[i].v], son[x] = e[i].v;
    }
    len[x] = len[son[x]] + 1;
}
void dfs(int x) {
    f[x][0] = 1;
    if (son[x]) f[son[x]] = f[x] + 1, dfs(son[x]), ans[x] = ans[son[x]] + 1;
    for (re int i = head[x]; i; i = e[i].nxt) {
        if (deep[e[i].v] < deep[x] || e[i].v == son[x]) continue;
        f[e[i].v] = id;
        id += len[e[i].v];
        dfs(e[i].v);
        for (re int j = 1; j <= len[e[i].v]; j++) {
            f[x][j] += f[e[i].v][j - 1];
            if (f[x][j] > f[x][ans[x]] ||
                (f[x][j] == f[x][ans[x]] && j < ans[x]))
                ans[x] = j;
        }
    }
    if (f[x][ans[x]] == 1) ans[x] = 0;
}
int main() {
    n = read();
    for (re int x, y, i = 1; i < n; i++)
        x = read(), y = read(), add(x, y), add(y, x);
    deep[1] = 1, dfs1(1);
    f[1] = id, id += len[1];
    dfs(1);
    for (re int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}