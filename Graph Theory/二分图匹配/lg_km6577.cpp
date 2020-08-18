#pragma GCC optimize(3, "inline", "Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505;
const ll inf = 1e18;
ll n, m;
ll wx[N], wy[N], weight[N][N], slack[N];
ll belong[N];
bool visx[N], visy[N];
ll pre[N];
void FindPath(ll u) {
    ll x, y = 0, yy = 0, delta;
    memset(pre, 0, sizeof pre);
    for (int i = 1; i <= n; i++) slack[i] = inf;
    belong[y] = u;
    while (1) {
        x = belong[y];
        delta = inf;
        visy[y] = 1;
        for (ll i = 1; i <= n; i++) {
            if (visy[i]) continue;
            if (slack[i] > wx[x] + wy[i] - weight[x][i]) {
                slack[i] = wx[x] + wy[i] - weight[x][i];
                pre[i] = y;
            }
            if (slack[i] < delta) {
                delta = slack[i];
                yy = i;
            }
        }
        for (ll i = 0; i <= n; i++) {
            if (visy[i])
                wx[belong[i]] -= delta, wy[i] += delta;
            else
                slack[i] -= delta;
        }
        y = yy;
        if (belong[y] == -1) break;
    }
    while (y) {
        belong[y] = belong[pre[y]];
        y = pre[y];
    }
}
ll Km() {
    memset(belong, -1, sizeof(belong));
    memset(wx, 0, sizeof(wx));
    memset(wy, 0, sizeof(wy));
    for (ll i = 1; i <= n; i++) {
        memset(visy, 0, sizeof(visy));
        FindPath(i);
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++)
        if (belong[i] != -1) res += weight[belong[i]][i];
    return res;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) weight[i][j] = -inf;
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        weight[u][v] = w;
    }
    printf("%lld\n", Km());
    for (int i = 1; i <= n; i++) printf("%lld ", belong[i]);
    return 0;
}