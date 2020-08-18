#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1e4 + 100;
const double eps = 1e-6;
struct Node {
    int next;
    int to;
    double vul;
} edge[maxn];

int head[maxn];
int tot;

int n, m, c[maxn], f[maxn], x[maxn], y[maxn], z[maxn];

int vis[maxn];
double dis[maxn];

void add(int from, int to, double vul) {
    edge[++tot].next = head[from];
    edge[tot].to = to;
    edge[tot].vul = vul;
    head[from] = tot;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        dis[i] = 0;
        vis[i] = 1;
    }
    memset(c, 0, sizeof(c));
    while (q.size()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = edge[i].next) {
            int y = edge[i].to;
            double z = edge[i].vul;
            if (dis[y] > dis[x] + z) {
                dis[y] = dis[x] + z;
                if (++c[y] > n) return 1;  // n个节点
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
    return 0;
}
bool pd(double w) {
    tot = 0;
    memset(head, 0, sizeof(head));
    for (int i = 1; i <= m; i++) add(x[i], y[i], w * z[i] - f[x[i]]);
    return spfa();
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
    for (int i = 1; i <= m; i++) scanf("%d %d %d", &x[i], &y[i], &z[i]);
    double l = 0, r = 1000;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (pd(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.2f", l);
    return 0;
}