// problem:1012
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <typename T>
inline void ckmax(T& x, T y) {
    x = (y > x ? y : x);
}
template <typename T>
inline void ckmin(T& x, T y) {
    x = (y < x ? y : x);
}

const int MAXN = 2000;
const int INF = 1e9;
int n;
struct EDGE {
    int nxt, to;
} edge[MAXN * 2 + 5];
int head[MAXN + 5], tot;
inline void add_edge(int u, int v) {
    edge[++tot].nxt = head[u], edge[tot].to = v, head[u] = tot;
}

struct Range_t {
    int l, r;
} rg[MAXN + 5];
int vals[MAXN * 2 + 5], cnt_val;
int f[MAXN + 5][MAXN * 2 + 5], pre[MAXN * 2 + 5], suf[MAXN * 2 + 5];
void dfs(int u, int fa) {
    for (int i = 1; i <= cnt_val; ++i) {
        f[u][i] = 0;
    }
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        for (int j = 1; j <= cnt_val; ++j) {
            f[u][j] += f[v][j];
        }
    }
    int l = lob(vals + 1, vals + cnt_val + 1, rg[u].l) - vals;
    int r = lob(vals + 1, vals + cnt_val + 1, rg[u].r) - vals;
    pre[0] = suf[cnt_val + 1] = INF;
    for (int i = 1; i <= cnt_val; ++i) {
        pre[i] = min(pre[i - 1], ((i >= l && i <= r) ? f[u][i] : INF));
    }
    for (int i = cnt_val; i >= 1; --i) {
        suf[i] = min(suf[i + 1], ((i >= l && i <= r) ? f[u][i] : INF));
    }
    for (int i = 1; i <= cnt_val; ++i) {
        f[u][i] = min(((i >= l && i <= r) ? f[u][i] : INF),
                      min(pre[i - 1], suf[i + 1]) + 1);
    }
}
void solve_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        head[i] = 0;
    }
    tot = 0;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    cnt_val = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> rg[i].l >> rg[i].r;
        vals[++cnt_val] = rg[i].l;
        vals[++cnt_val] = rg[i].r;
    }
    vals[++cnt_val] = 0;
    sort(vals + 1, vals + cnt_val + 1);
    cnt_val = unique(vals + 1, vals + cnt_val + 1) - (vals + 1);
    dfs(1, 0);
    cout << "fk --" << endl;
    for (int i = 1; i <= cnt_val; ++i) cout << vals[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= cnt_val; ++j) cout << f[i][j] << " ";
        cout << endl;
    }
    int pos = lob(vals + 1, vals + cnt_val + 1, 0) - vals;
    cout << f[1][pos] << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve_case();
    return 0;
}