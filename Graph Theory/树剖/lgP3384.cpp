//N个结点的树，

// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100, maxn = 1e6 + 100;
int n, m, r, mod;
struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot;
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}
int w[N], wt[N], a[maxn << 2], lazy[maxn << 2];  // w[]、wt[]初始点权数组
int son[maxn], id[maxn], fa[maxn], cnt, dep[maxn], siz[maxn], top[maxn];
// son[]重儿子编号,id[]新编号,fa[]父亲节点,cnt
// dfs_clock/dfs序,dep[]深度,siz[]子树大小,top[]当前链顶端节点
int res = 0;
void pushdown(int rt, int len) {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    a[rt << 1] += lazy[rt] * (len - (len >> 1));
    a[rt << 1 | 1] += lazy[rt] * (len >> 1);
    a[rt << 1] %= mod;
    a[rt << 1 | 1] %= mod;
    lazy[rt] = 0;
}
void build(int rt, int l, int r) {
    if (l == r) {
        a[rt] = wt[l];
        if (a[rt] > mod) a[rt] %= mod;
        return;
    }
    build(rt << 1, l, (l + r) >> 1);
    build(rt << 1 | 1, ((l + r) >> 1) + 1, r);
    a[rt] = (a[rt << 1] + a[rt << 1 | 1]) % mod;
}
void query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        res += a[rt];
        res %= mod;
        return;
    } else {
        if (lazy[rt]) pushdown(rt, r - l + 1);
        if (L <= ((l + r) >> 1)) query(rt << 1, l, (l + r) >> 1, L, R);
        if (R > (l + r) >> 1) query(rt << 1 | 1, ((r + l) >> 1) + 1, r, L, R);
    }
}
void update(int rt, int l, int r, int L, int R, int k) {
    if (L <= l && r <= R) {
        lazy[rt] += k;
        a[rt] += k * (r - l + 1);
    } else {
        if (lazy[rt]) pushdown(rt, r - l + 1);
        if (L <= ((l + r) >> 1)) update(rt << 1, l, (l + r) >> 1, L, R, k);
        if (R > (l + r) >> 1)
            update(rt << 1 | 1, ((r + l) >> 1) + 1, r, L, R, k);
        a[rt] = (a[rt << 1] + a[rt << 1 | 1]) % mod;
    }
}
inline int qRange(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {  //当两个点不在同一条链上
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);  //把x点改为所在链顶端的深度更深的那个点
        res = 0;
        query(1, 1, n, id[top[x]],
              id[x]);  // ans加上x点到x所在链顶端 这一段区间的点权和
        ans += res;
        ans %= mod;      //按题意取模
        x = fa[top[x]];  //把x跳到x所在链顶端的那个点的上面一个点
    }
    //直到两个点处于一条链上
    if (dep[x] > dep[y]) swap(x, y);  //把x点深度更深的那个点
    res = 0;
    query(1, 1, n, id[x], id[y]);  //这时再加上此时两个点的区间和即可
    ans += res;
    return ans % mod;
}

inline void updRange(int x, int y, int k) {  //同上
    k %= mod;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, 1, n, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, 1, n, id[x], id[y], k);
}

inline int qSon(int x) {
    res = 0;
    query(1, 1, n, id[x], id[x] + siz[x] - 1);  //子树区间右端点为id[x]+siz[x]-1
    return res;
}

inline void updSon(int x, int k) {  //同上
    update(1, 1, n, id[x], id[x] + siz[x] - 1, k);
}

inline void dfs1(int x, int f, int deep) {  // x当前节点，f父亲，deep深度
    dep[x] = deep;                          //标记每个点的深度
    fa[x] = f;                              //标记每个点的父亲
    siz[x] = 1;       //标记每个非叶子节点的子树大小
    int maxson = -1;  //记录重儿子的儿子数
    for (int i = head[x]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        if (y == f) continue;  //若为父亲则continue
        dfs1(y, x, deep + 1);  // dfs其儿子
        siz[x] += siz[y];      //把它的儿子数加到它身上
        if (siz[y] > maxson)
            son[x] = y, maxson = siz[y];  //标记每个非叶子节点的重儿子编号
    }
}

inline void dfs2(int x, int topf) {  // x当前节点，topf当前链的最顶端的节点
    id[x] = ++cnt;                   //标记每个点的新编号
    wt[cnt] = w[x];       //把每个点的初始值赋到新编号上来
    top[x] = topf;        //这个点所在链的顶端
    if (!son[x]) return;  //如果没有儿子则返回
    dfs2(son[x], topf);  //按先处理重儿子，再处理轻儿子的顺序递归处理
    for (int i = head[x]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        if (y == fa[x] || y == son[x]) continue;
        dfs2(y, y);  //对于每一个轻儿子都有一条从它自己开始的链
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r >> mod;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, 1), add_edge(v, u, 1);
    }
    dfs1(r, 0, 1);
    dfs2(r, r);
    build(1, 1, n);
    while (m--) {
        int op, x, y, z;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            updRange(x, y, z);
        } else if (op == 2) {
            cin >> x >> y;
            cout << qRange(x, y) << endl;
        }else if(op==3){
            cin >> x >> y;
            updSon(x , y);
        }else {
            cin >> x;
            cout << qSon(x) << endl;
        }
    }
    return 0;
}