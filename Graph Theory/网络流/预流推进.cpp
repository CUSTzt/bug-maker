#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define sz(a) ((int)a.size())
#define mem(a, b) memset(a, b, sizeof a)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define gmid (l + r >> 1)
const int maxn = 2.5e3 + 5;
const int maxm = 2.4e5 + 5;
const int mod = 1e9 + 7;
const ll inf = INT_MAX;

template <class ll>
struct HLPP {
    struct Edge {
        int v, rev;
        ll cap;
    };
    int n, sp, tp, lim, ht, lcnt;
    ll exf[maxn];
    vector<Edge> G[maxn];
    vector<int> hq[maxn], gap[maxn], h, sum;
    void init(int s, int t, int nn) {
        sp = s, tp = t, n = nn, lim = n + 1, ht = lcnt = 0;
        for (int i = 0; i <= n + 1000; ++i) G[i].clear(), exf[i] = 0;
    }
    void add(int u, int v, ll cap) {
        G[u].pb({v, sz(G[v]), cap});
        G[v].pb({u, sz(G[u]) - 1, 0});
    }
    void update(int u, int nh) {
        ++lcnt;
        if (h[u] != lim) --sum[h[u]];
        h[u] = nh;
        if (nh == lim) return;
        ++sum[ht = nh];
        gap[nh].pb(u);
        if (exf[u] > 0) hq[nh].pb(u);
    }
    void relabel() {
        queue<int> q;
        for (int i = 0; i <= lim; ++i) hq[i].clear(), gap[i].clear();
        h.assign(lim, lim), sum.assign(lim, 0), q.push(tp);
        lcnt = ht = h[tp] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (Edge &e : G[u]) {
                if (h[e.v] == lim && G[e.v][e.rev].cap)
                    update(e.v, h[u] + 1), q.push(e.v);
            }
            ht = h[u];
        }
    }
    void push(int u, Edge &e) {
        if (!exf[e.v]) hq[h[e.v]].pb(e.v);
        ll df = min(exf[u], e.cap);
        e.cap -= df, G[e.v][e.rev].cap += df;
        exf[u] -= df, exf[e.v] += df;
    }
    void discharge(int u) {
        int nh = lim;
        if (h[u] == lim) return;
        for (Edge &e : G[u]) {
            if (!e.cap) continue;
            if (h[u] == h[e.v] + 1) {
                push(u, e);
                if (exf[u] <= 0) return;
            } else if (nh > h[e.v] + 1)
                nh = h[e.v] + 1;
        }
        if (sum[h[u]] > 1)
            update(u, nh);
        else {
            for (; ht >= h[u]; gap[ht--].clear())
                for (int &i : gap[ht]) update(i, lim);
        }
    }
    ll solve() {
        exf[sp] = inf, exf[tp] = -inf, relabel();
        for (Edge &e : G[sp]) push(sp, e);
        for (; ~ht; --ht) {
            while (!hq[ht].empty()) {
                int u = hq[ht].back();
                hq[ht].pop_back();
                discharge(u);
                if (lcnt > (n << 2)) relabel();
            }
        }
        return exf[tp] + inf;
    }
};

const int maxs = 1e4 + 5;

int main() {
    HLPP<int> hlpp;
    int T, full_flow = 0;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n, m;
        full_flow = 0;
        scanf("%d%d", &n, &m);
        int src = 0, dst = 500 + n + 1;
        hlpp.init(src, dst, 500 + 2 + n);
        bool vis[maxn];  //表示第i天是否被用到
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            int P, S, E;
            scanf("%d%d%d", &P, &S, &E);
            hlpp.add(src, 500 + i, P);
            full_flow += P;
            for (int j = S; j <= E; ++j) {
                hlpp.add(500 + i, j, 1);
                vis[j] = true;
            }
        }
        for (int i = 1; i <= 500; ++i)
            if (vis[i])  //被任务覆盖的日子才添加边
                hlpp.add(i, dst, m);

        // cout << hlpp.solve() << "    " << full_flow << endl;
        printf("Case %d: %s\n\n", kase, hlpp.solve() == full_flow ? "Yes" : "No");
    }

    return 0;
}