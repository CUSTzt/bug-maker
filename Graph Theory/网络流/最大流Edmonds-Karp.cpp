#include <bits/stdc++.h>

using namespace std;
#define int long long
// 时间复杂度为 O(nm^2)
// 实际运用时候远远达不到这个上界，效率较高，可以处理1000~10000
const int inf = 1 << 29, N = 2010, M = 20010;
int head[N << 1], ver[M << 1], Next[M << 1], edge[M << 1], v[N << 1],
    incf[N << 1], pre[N << 1];
int n, m, s, t, tot, maxflow;
void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
    ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

bool bfs() {
    memset(v, 0, sizeof v);
    queue<int> q;
    while (q.size()) q.pop();
    q.push(s);
    v[s] = 1;
    incf[s] = inf;  // 增广路上各边的最小剩余容量
    while (q.size()) {
        // cout << q.size() << endl;
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = Next[i]) {
            if (edge[i]) {
                int y = ver[i];
                if (v[y]) continue;
                incf[y] = min(incf[x], edge[i]);
                pre[y] = i;  // 记录前驱，便于找到最长路的实际方案
                q.push(y), v[y] = 1;
                if (y == t) return 1;
            }
        }
    }
    return 0;
}
void update() {  // 更新增广路及其反向边的剩余容量
    int x = t;
    while (x != s) {
        int i = pre[x];
        edge[i] -= incf[t];
        edge[i ^ 1] += incf[t];  // 成对存储的 xor 1 的技巧
        x = ver[i ^ 1];
    }
    maxflow += incf[t];
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s >> t;
    tot = 1;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        add(u , v , c);
    }
    while(bfs()) update();
    cout << maxflow << endl;
}