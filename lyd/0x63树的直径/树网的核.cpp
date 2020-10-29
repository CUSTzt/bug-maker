#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 500010, M = N * 2;
int n, s;
int h[N], e[M], w[M], ne[M], idx;
int q[N], dist[N], pre[N];
vector<PII> path;
bool st[N];
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void bfs(int start) {
    int hh = 0, tt = 0;
    memset(dist, 0x3f, sizeof dist);
    memset(pre, -1, sizeof pre);
    dist[start] = 0;
    q[0] = start;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                pre[j] = t;
                dist[j] = dist[t] + w[i];
                q[++tt] = j;
            }
        }
    }
}
int bfs_max_dist(int start) {
    int res = 0;
    int hh = 0, tt = 0;
    q[0] = start;
    while (hh <= tt) {
        int t = q[hh++];
        res = max(res, dist[t]);
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                dist[j] = dist[t] + w[i];
                q[++tt] = j;
            }
        }
    }
    return res;
}
int get_max() {
    int t = 1;
    for (int i = 1; i <= n; i++)
        if (dist[t] < dist[i]) t = i;
    return t;
}
bool check(int mid) {
    int u = 0, v = path.size() - 1;
    while (u + 1 < path.size() && path[u + 1].second <= mid) u++;
    while (v - 1 >= 0 && path.back().second - path[v - 1].second <= mid) v--;
    if (u > v) return true;
    if (path[v].second - path[u].second > s) return false;
    memset(st, false, sizeof st);
    memset(dist, 0, sizeof dist);
    for (auto p : path) st[p.first] = true;
    for (int i = u; i <= v; i++)
        if (bfs_max_dist(path[i].first) > mid) return false;
    return true;
}
int main() {
    scanf("%d%d", &n, &s);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    bfs(1); int u = get_max();
    bfs(u); int v = get_max();
    while (v != -1) {
        path.push_back({v, dist[v]});
        v = pre[v];
    }
    reverse(path.begin(), path.end());
    int l = 0, r = 2e9;
    while (l < r) {
        int mid = (LL)l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);
    return 0;
}
