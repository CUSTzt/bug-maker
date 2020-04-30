// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
const int N = 3e5 + 10;
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
struct Node {
    int u, v, w;
} e[N];
int cmp(Node a, Node b) { return a.w < b.w; }

int fa[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int d[N], f[N][25], g[N][25][3];
int calc()
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}