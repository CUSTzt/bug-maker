//奇环中有2k+1个点，所以最多有k组匹配。这就是说，有一个点没有匹配，
//即这个点在环内两边的连边都不是匹配边，也只有这个点可以向环外连边。
//发现了这个性质，我们可以把整个奇环缩成一个点。缩完点后的图如果可以找到一条增广路，
//那么原图中也可以找到一条增广路，因为如果增广路经过奇环那么奇环内的增广路可以还原出来。
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 510;
int n, m, x, y;
vector<int> g[N];
namespace Blossom {
int mate[N], n, ret, nxt[N], f[N], mark[N], vis[N], t;
queue<int> Q;
int F(int x) { return x == f[x] ? x : f[x] = F(f[x]); }
void merge(int a, int b) { f[F(a)] = F(b); }
int lca(int x, int y) {
    for (t++;; swap(x, y))
        if (~x) {
            if (vis[x = F(x)] == t) return x;
            vis[x] = t;
            x = mate[x] != -1 ? nxt[mate[x]] : -1;
        }
}
void group(int a, int p) {
    for (int b, c; a != p; merge(a, b), merge(b, c), a = c) {
        b = mate[a], c = nxt[b];
        if (F(c) != p) nxt[c] = b;
        if (mark[b] == 2) mark[b] = 1, Q.push(b);
        if (mark[c] == 2) mark[c] = 1, Q.push(c);
    }
}
void aug(int s, const vector<int> G[]) {
    for (int i = 0; i < n; ++i) nxt[i] = vis[i] = -1, f[i] = i, mark[i] = 0;
    while (!Q.empty()) Q.pop();
    Q.push(s);
    mark[s] = 1;
    while (mate[s] == -1 && !Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0, y; i < (int)G[x].size(); ++i) {
            if ((y = G[x][i]) != mate[x] && F(x) != F(y) && mark[y] != 2) {
                if (mark[y] == 1) {
                    int p = lca(x, y);
                    if (F(x) != p) nxt[x] = y;
                    if (F(y) != p) nxt[y] = x;
                    group(x, p), group(y, p);
                } else if (mate[y] == -1) {
                    nxt[y] = x;
                    for (int j = y, k, l; ~j; j = l)
                        k = nxt[j], l = mate[k], mate[j] = k, mate[k] = j;
                    break;
                } else
                    nxt[y] = x, Q.push(mate[y]), mark[mate[y]] = 1, mark[y] = 2;
            }
        }
    }
}
int solve(int _n, const vector<int> G[]) {
    n = _n;
    memset(mate, -1, sizeof mate);
    for (int i = t = 0; i < n; ++i)
        if (mate[i] == -1) aug(i, G);
    for (int i = ret = 0; i < n; ++i) ret += mate[i] > i;
    printf("%d\n", ret);
    for (int i = 0; i < n; i++) printf("%d ", mate[i] + 1);
    return ret;
}
}  // namespace Blossom
int main() {
    scanf("%d%d", &n, &m);
    while (m--)
        scanf("%d%d", &x, &y), x--, y--, g[x].push_back(y), g[y].push_back(x);
    Blossom::solve(n, g);
}
