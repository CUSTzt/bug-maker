#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 405, M = 1000000010;
const ll NOT =0/*-1LL * N * M*/, INF = 3LL * N * M;
int n, nl, nr, m, z, py, x, y, i, j, p, lk[N], pre[N];
bool vy[N];
ll lx[N], ly[N], d, w[N][N], slk[N], ans;
void add(int x, int y, ll z) {
    if (w[y][x] < z) w[y][x] = z;
}
int main() {
    scanf("%d%d%d", &nl, &nr, &m);
    n = max(nl, nr);
    for (i = 0; i <= n; i++) lk[i] = pre[i] = lx[i] = ly[i] = slk[i] = 0;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++) w[i][j] = NOT;
    while (m--) scanf("%d %d %d", &x, &y, &z), add(x, y, z);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) lx[i] = max(lx[i], w[i][j]);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) slk[j] = INF, vy[j] = 0;
        for (lk[py = 0] = i; lk[py]; py = p) {
            vy[py] = 1;
            d = INF;
            x = lk[py];
            for (y = 1; y <= n; y++)
                if (!vy[y]) {
                    if (lx[x] + ly[y]-w[x][y] < slk[y])
                        slk[y] = lx[x] + ly[y]-w[x][y], pre[y] = py;
                    if (slk[y] < d) d = slk[y], p = y;
                }
            for (y = 0; y <= n; y++)
                if (vy[y])
                    lx[lk[y]]-= d, ly[y] += d;
                else
                    slk[y]-= d;
        }
        for (; py; py = pre[py]) lk[py] = lk[pre[py]];
    }
    for (ans = 0, i = 1; i <= n; i++) {
        ans += lx[i] + ly[i];
        if (w[lk[i]][i] == NOT) ans-= NOT;
    }
    printf("%lld\n", ans);
    for (i = 1; i <= nl; i++) printf("%d ", w[lk[i]][i] != NOT ? lk[i] : 0);
}
