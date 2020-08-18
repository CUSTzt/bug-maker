#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N = 5e4 + 10;

int n;

int L, R;
int sum[N << 2], add[N << 2];
#define mid ((l + r) >> 1)
#define lc (rt << 1)
#define rc (rt << 1 | 1)
void pushup(int rt) { sum[rt] = sum[lc] + sum[rc]; }
void push_down(int rt, int l, int r) {
    if (add[rt]) {
        add[lc] += add[rt];
        add[rc] += add[rt];
        sum[lc] += add[rt] * (mid - l + 1);
        sum[rc] += add[rt] * (r - mid);
        add[rt] = 0;
    }
}
void build(int rt, int l, int r) {
    sum[rt] = add[rt] = 0;
    if (l == r) return;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}
void update(int rt, int l, int r) {
    if (L <= l && r <= R) {
        sum[rt] += (r - l + 1) * 2;
        add[rt] += 2;
        return;
    }
    push_down(rt, l, r);
    if (L <= mid) update(lc, l, mid);
    if (R > mid) update(rc, mid + 1, r);
    pushup(rt);
}
int query(int rt, int l, int r) {
    if (L <= l && r <= R) return sum[rt];
    push_down(rt, l, r);
    int res = 0;
    if (L <= mid) res += query(lc, l, mid);
    if (R > mid) res += query(rc, mid + 1, r);
    return res;
}

int g[N], nxt[N << 1], v[N << 1], ed;
int st[N], d[N], son[N], sz[N], f[N], top[N], dfn;
void ADD(int x, int y) { v[++ed] = y, nxt[ed] = g[x], g[x] = ed; }
void dfs(int x) {
    sz[x] = 1;
    for (int i = g[x]; i; i = nxt[i])
        if (v[i] != f[x]) {
            f[v[i]] = x, d[v[i]] = d[x] + 1;
            dfs(v[i]), sz[x] += sz[v[i]];
            if (sz[v[i]] > sz[son[x]]) son[x] = v[i];
        }
}
void dfs2(int x, int y) {
    st[x] = ++dfn;
    top[x] = y;
    if (son[x]) dfs2(son[x], y);
    for (int i = g[x]; i; i = nxt[i])
        if (v[i] != son[x] && v[i] != f[x]) dfs2(v[i], v[i]);
}
int lca2(int x, int y) {
    int t;
    while (top[x] != top[y]) t = top[y], y = f[top[y]];
    return x == y ? t : son[x];
}

int res = 0;
void chain(int x, int y, int t = 0) {
    for (; top[x] != top[y]; x = f[top[x]]) {
        if (d[top[x]] < d[top[y]]) {
            int z = x;
            x = y;
            y = z;
        }
        L = st[top[x]], R = st[x];
        if (!t)
            update(1, 1, n);
        else
            res += query(1, 1, n);
    }
    if (d[x] < d[y]) {
        int z = x;
        x = y;
        y = z;
    }
    L = st[y], R = st[x];
    if (!t)
        update(1, 1, n);
    else
        res += query(1, 1, n);
}

int a[N];

void solve() {
    int _;
    dfn = 0;
    cin >> n >> _;
    build(1, 1, n);
    ed = 0;
    for (int i = 1; i <= n; i++) g[i] = a[i] = son[i] = 0;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        ADD(x, y), ADD(y, x);
    }
    dfs(1);
    dfs2(1, 0);
    int val = 0, cnt = 0;
    while (_--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            int y;
            cin >> y;
            if (x != 1) chain(lca2(1, x), x);
            val += y - d[x];
            cnt++;
        } else if (op == 2) {
            res = 0;
            chain(1, x, 1);
            int tp = a[x] + val - d[x] * cnt + res;
            if (tp > 0) a[x] -= tp;
        } else {
            res = 0;
            chain(1, x, 1);
            cout << a[x] + val - d[x] * cnt + res << endl;
        }
    }
}
int main() {
    //    IN;
    IOS;
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}