#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 1050;
bool g[maxn][maxn], inque[maxn], inpath[maxn];
bool inhua[maxn];
int st, ed, newbase, ans, n;
int base[maxn], pre[maxn], match[maxn];
int head, tail, que[maxn];
int x[maxn], y[maxn], f[maxn], mp[maxn][maxn], ne, np;

void Push(int u) {
    que[tail] = u;
    tail++;
    inque[u] = 1;
}
int Pop() {
    int res = que[head];
    head++;
    return res;
}

int lca(int u, int v)  //寻找公共花祖先
{
    memset(inpath, 0, sizeof(inpath));
    while (1) {
        u = base[u];
        inpath[u] = 1;
        if (u == st) break;
        u = pre[match[u]];
    }
    while (1) {
        v = base[v];
        if (inpath[v]) break;
        v = pre[match[v]];
    }
    return v;
}
void reset(int u)  //缩环
{
    int v;
    while (base[u] != newbase) {
        v = match[u];
        inhua[base[u]] = inhua[base[v]] = 1;
        u = pre[v];
        if (base[u] != newbase) pre[u] = v;
    }
}
void contract(int u, int v)  //
{
    newbase = lca(u, v);
    memset(inhua, 0, sizeof(inhua));
    reset(u);
    reset(v);
    if (base[u] != newbase) pre[u] = v;
    if (base[v] != newbase) pre[v] = u;
    for (int i = 1; i <= n; i++) {
        if (inhua[base[i]]) {
            base[i] = newbase;
            if (!inque[i]) Push(i);
        }
    }
}
void findaug() {
    memset(inque, 0, sizeof(inque));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)  //并查集
        base[i] = i;
    head = tail = 1;
    Push(st);
    ed = 0;
    while (head < tail) {
        int u = Pop();
        for (int v = 1; v <= n; v++) {
            if (g[u][v] && (base[u] != base[v]) && match[u] != v) {
                if (v == st || (match[v] > 0) && pre[match[v]] > 0)  //成环
                    contract(u, v);
                else if (pre[v] == 0) {
                    pre[v] = u;
                    if (match[v] > 0)
                        Push(match[v]);
                    else  //找到增广路
                    {
                        ed = v;
                        return;
                    }
                }
            }
        }
    }
}
void aug() {
    int u, v, w;
    u = ed;
    while (u > 0) {
        v = pre[u];
        w = match[v];
        match[v] = u;
        match[u] = v;
        u = w;
    }
}
void edmonds()  //匹配
{
    memset(match, 0, sizeof(match));
    for (int u = 1; u <= n; u++) {
        if (match[u] == 0) {
            st = u;
            findaug();          //以st开始寻找增广路
            if (ed > 0) aug();  //找到增广路  重新染色，反向
        }
    }
}
//以上是带花树求最大匹配算法  不用看

void create()  //建图
{
    n = 0;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= np; i++)
        for (int j = 1; j <= f[i]; j++)
            mp[i][j] = ++n;         //拆点，给每个度的点编号
    for (int i = 0; i < ne; i++) {  //此时n+1代表x,n+2代表y
        for (int j = 1; j <= f[x[i]]; j++)
            g[mp[x[i]][j]][n + 1] = g[n + 1][mp[x[i]][j]] =
                1;  //每个度的点与对应的x,y相连
        for (int j = 1; j <= f[y[i]]; j++)
            g[mp[y[i]][j]][n + 2] = g[n + 2][mp[y[i]][j]] = 1;
        g[n + 1][n + 2] = g[n + 2][n + 1] = 1;  // x与y相连
        n += 2;
    }
}
void print() {
    ans = 0;
    for (int i = 1; i <= n; i++)
        if (match[i] != 0) {
            ans++;
            //            if(match[i]>i)
            //            cout<<"_____"<<i<<' '<<match[i]<<endl;
        }
    // cout<<"******"<<ans<<' '<<n<<endl;
    if (ans == n)
        printf("Yes\n");
    else
        printf("No\n");
}
int main() {
    int t, k = 0;
    // scanf("%d",&t);
    // while(t--)
    // {
    while (~scanf("%d%d", &np, &ne)) {
        for (int i = 1; i <= np; i++) scanf("%d", &f[i]);
        for (int i = 0; i < ne; i++) scanf("%d%d", &x[i], &y[i]);
        // printf("Case %d: ", ++k);
        create();
        edmonds();
        print();
    }
    // }
    return 0;
}