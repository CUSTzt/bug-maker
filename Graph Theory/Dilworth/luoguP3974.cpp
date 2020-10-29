#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = 1e18;
const ll LARGE = 1e12;
int n, m;
queue<int> q;
vector<bool> inq;
vector<ll> raw_cap, cap, cost, dis;
vector<int> head, nxt, from, to, pre;
void add(int u, int v, ll f, ll w) {
    nxt.push_back(head[u]);
    head[u] = to.size();
    from.push_back(u);
    to.push_back(v);
    raw_cap.push_back(f);
    cap.push_back(0);
    cost.push_back(w);
}
void add_edge(int u, int v, ll f, ll w) {
    add(u, v, f, w);
    add(v, u, 0, -w);
}
void spfa(int s) {
    inq.assign(n + 1, false);
    dis.assign(n + 1, INF);
    pre.assign(n + 1, -1);
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        inq[u] = false;
        q.pop();
        for (int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            ll w = cost[i];
            if (cap[i] && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = i;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
void add_one_cap(int id) {
    int u = from[id];
    int v = to[id];
    if (cap[id]) {
        ++cap[id];
        return;
    }
    spfa(v);
    if (dis[u] < INF && dis[u] + cost[id] < 0) {
        ++cap[id ^ 1];
        while (u != v) {
            int x = pre[u];
            --cap[x];
            ++cap[x ^ 1];
            u = from[x];
        }
    } else
        ++cap[id];
}
int main() {
    int s, t;
    cin >> n >> m >> s >> t;
    head.resize(n + 1, -1);
    for (int i = 1; i <= m; ++i) {
        ll u, v, f, w;
        cin >> u >> v >> f >> w;
        add_edge(u, v, f, w);
    }
    add_edge(t, s, LARGE, -LARGE);
    for (int i = 40; i >= 0; --i) {
        for (int j = 0; j <= m * 2 + 1; ++j) cap[j] <<= 1;
        for (int j = 0; j <= m * 2; j += 2) {
            if ((raw_cap[j] >> i) & 1) {
                add_one_cap(j);
            }
        }
    }
    ll min_cost = 0;
    for (int i = 0; i < m; ++i) min_cost += cap[i << 1 | 1] * cost[i << 1];
    cout << cap[m << 1 | 1] << ' ' << min_cost;
    return 0;
}
