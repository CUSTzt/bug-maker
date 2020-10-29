#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
typedef pair<int, int> P;
struct Edge {
    int u, v, next;
} e[MAXN << 1];
int head[MAXN], cnt;
bool vis[MAXN];
int dep[MAXN];
int in[MAXN];

void addedge(int u, int v) {
    e[cnt] = {u, v, head[u]};
    head[u] = cnt++;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k >= 14) {
        cout << "No" << endl;
        return 0;
    }
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
        in[v]++;
        in[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 1) q.push(i), vis[i] = true;
    int root;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        root = u;
        for (int i = head[u]; ~i; i = e[i].next) {
            if (!vis[e[i].v]) q.push(e[i].v), vis[e[i].v] = true;
        }
    }
    queue<pair<int, int> > que;
    que.push(P(root, -1));
    dep[root] = 0;
    int flag = 0, mx;

    while (!que.empty()) {
        int u = que.front().first, fa = que.front().second;
        que.pop();
        mx = dep[u];
        int sum = 0;
        for (int i = head[u]; ~i; i = e[i].next) {
            if (e[i].v != fa) {
                que.push(P(e[i].v, u));
                dep[e[i].v] = dep[u] + 1;
                sum++;
            }
        }
        if (dep[u] + 1 <= k && sum < 3) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        cout << "No" << endl;
        return 0;
    }
    if (mx == k)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
