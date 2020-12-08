/*
主席树+启发式合并.
一开始用树剖搞lca 发现很麻烦
然后换成了倍增.
用并查集维护连通性.
合并的话就是暴力重构更新x所在连通块的信息.
要把小的联通块重构掉.
每个点最多重构logn次.
然后lca维护也是log的.
时空复杂度都是O(nlogn2)的.
这题显然可以splay查个排名啥的(懒没写~
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 160001
#define D 20
using namespace std;
int n, m, qq, tot, cut, ans, father[MAXN], dis[MAXN];
int head[MAXN], size[MAXN], deep[MAXN], root[MAXN], s[MAXN], fa[MAXN][D + 5];
struct edge {
    int v, next;
} e[MAXN * 2];
struct data {
    int lc, rc, size;
} tree[MAXN * 75];
struct node {
    int x, o;
} a[MAXN];
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}
void add(int u, int v) {
    e[++cut].v = v;
    e[cut].next = head[u];
    head[u] = cut;
}
bool cmp(const node &x, const node &y) {
    if (x.x == y.x) return x.o < y.o;
    return x.x < y.x;
}
int find(int x) { return x != father[x] ? father[x] = find(father[x]) : x; }
void change(int &k, int last, int l, int r, int x) {
    k = ++tot;
    tree[k].lc = tree[last].lc, tree[k].rc = tree[last].rc;
    tree[k].size = tree[last].size + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid)
        change(tree[k].lc, tree[last].lc, l, mid, x);
    else
        change(tree[k].rc, tree[last].rc, mid + 1, r, x);
    return;
}
int query(int L, int R, int lc, int falc, int l, int r, int k) {
    if (l == r) return l;
    int sum = tree[tree[R].lc].size + tree[tree[L].lc].size -
              tree[tree[lc].lc].size - tree[tree[falc].lc].size;
    int mid = l + r >> 1;
    if (sum >= k)
        return query(tree[L].lc, tree[R].lc, tree[lc].lc, tree[falc].lc, l, mid,
                     k);
    else
        return query(tree[L].rc, tree[R].rc, tree[lc].rc, tree[falc].rc,
                     mid + 1, r, k - sum);
}
void dfs1(int u, int f) {
    size[u] = 1;
    fa[u][0] = f;
    int p = lower_bound(s + 1, s + n + 1, a[u].x) - s;
    change(root[u], root[f], 1, n, p);
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v != f) deep[v] = deep[u] + 1, dfs1(v, u), size[u] += size[v];
    }
    return;
}
void get_father() {
    for (int j = 1; j <= D; j++)
        for (int i = 1; i <= n; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
    return;
}
int get_same(int u, int x) {
    for (int i = 0; i <= D; i++)
        if (x & (1 << i)) u = fa[u][i];
    return u;
}
int lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    x = get_same(x, deep[x] - deep[y]);
    if (x == y) return x;
    for (int i = D; i >= 0; i--)
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
void slovequery(int x, int y, int k) {
    int lc = lca(x, y);
    ans = query(root[x], root[y], root[lc], root[fa[lc][0]], 1, n, k);
    ans = s[ans];
    printf("%d\n", ans);
    return;
}
void slove(int u, int f) {
    fa[u][0] = f;
    deep[u] = deep[f] + 1;
    int p = lower_bound(s + 1, s + n + 1, a[u].x) - s;
    change(root[u], root[f], 1, n, p);
    for (int i = 1; i <= D; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v != f) slove(v, u);
    }
    return;
}
void union_(int x, int y) {
    int l1 = find(x), l2 = find(y);
    if (size[l1] > size[l2]) swap(l1, l2), swap(x, y);
    add(x, y), add(y, x);
    father[l1] = l2, size[l1] += size[l2];
    slove(x, y);  // get_father(); 1 T.
    return;
}
int main() {
    int t, x, y, z;
    char ch[5];
    //  freopen("forest.in","r",stdin);
    //  freopen("forest.out","w",stdout);
    t = read();
    n = read();
    m = read(), qq = read();
    for (int i = 1; i <= n; i++)
        father[i] = i, a[i].x = read(), a[i].o = i, s[i] = a[i].x;
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= m; i++) {
        x = read(), y = read(), add(x, y), add(y, x);
        int l1 = find(x), l2 = find(y);
        father[l2] = l1;
    }
    for (int i = 1; i <= n; i++)
        if (!fa[i][0]) dfs1(i, 0);
    get_father();
    while (qq--) {
        scanf("%s", ch);
        if (ch[0] == 'Q') {
            x = read(), y = read(), z = read();
            x ^= ans, y ^= ans, z ^= ans;
            slovequery(x, y, z);
        } else {
            x = read(), y = read();
            x ^= ans, y ^= ans;
            union_(x, y);
        }
    }
    return 0;
}