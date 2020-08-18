#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int head[maxn], nt[maxn * 2], to[maxn * 2], w[maxn * 2], tot;
int n, d[maxn], b[maxn], top[maxn], ts, Size[maxn], k;
void add(int u, int v, int z) {
    to[++tot] = v;
    nt[tot] = head[u];
    w[tot] = z;
    head[u] = tot;
}
bool vis[maxn];
void get_dis(int pos, int fa) {
    top[++ts] = d[pos];
    for (int i = head[pos]; i; i = nt[i]) {
        int y = to[i], z = w[i];
        if (y == fa || vis[y]) continue;
        d[y] = d[pos] + z;
        get_dis(y, pos);
    }
}
int ans = 1e9, rt, sz;
void get_rt(int pos, int fa) {
    int mx = 0;
    Size[pos] = 1;
    for (int i = head[pos]; i; i = nt[i]) {
        int y = to[i], z = w[i];
        if (y == fa || vis[y]) continue;
        get_rt(y, pos);
        Size[pos] += Size[y];
        mx = max(mx, Size[y]);
    }
    mx = max(mx, sz - Size[pos]);
    if (mx < ans) ans = mx, rt = pos;
}
int solve(int pos, int dis) {
    d[pos] = dis;
    ts = 0;
    get_dis(pos, pos);
    sort(top + 1, top + 1 + ts);
    int l = 1, r = ts;
    int rec = 0;
    for (; l < r; l++) {
        while (top[l] + top[r] > k) r--;
        if (l < r) rec += r - l;
    }
    return rec;
}
long long sum = 0;
void dfs(int pos) {
    vis[pos] = true;
    sum += solve(pos, 0);
    for (int i = head[pos]; i; i = nt[i]) {
        int y = to[i], z = w[i];
        if (vis[y]) continue;
        sum -= solve(y, z);
        ans = 2e9;
        rt = 0;
        sz = Size[y];
        get_rt(y, 0);
        dfs(rt);
    }
    return;
}
int main() {
    while (~scanf("%d%d", &n, &k)) {
        if (n == 0 && k == 0) break;
        for (int i = 0; i <= n + 10; i++) head[i] = 0, vis[i] = 0;
        tot = 0;
        for (int i = 1; i < n; i++) {
            int t1, t2, t3;
            scanf("%d%d%d", &t1, &t2, &t3);
            add(t1, t2, t3);
            add(t2, t1, t3);
        }
        sz = n;
        sum = 0;
        dfs(1);
        cout << sum << endl;
    }
}