//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
using LL = long long;
const int maxn = 1000050, INF=0x3f3f3f3f;
int fa[1000050];
void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
const int N = 1e6 + 10;
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
int s[maxn][2], f[maxn][2], ans, t, k;
void dfs(int u) {
    int ret = INF;
    f[u][0] = 0;
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != k) dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        ret = min(ret, max(f[v][0], f[v][1]) - f[v][0]);
        // cout <<"ret ==== " << ret << endl;
    }
    f[u][1] = f[u][0] + 1 - ret;
}
int main() {
    int n;
    cin >> n;
    init(n + 10);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int p = find(x), q = find(i);
        if (p == q) {
            s[++t][0] = x;
            s[t][1] = i;
        } else {
            add_edge(x, i, 1);
            fa[q] = p;
        }
    }
    for (int i = 1; i <= t; i++) {
        k = 0;
        dfs(s[i][0]);
        k = s[i][0];
        dfs(s[i][1]);
        int now = f[s[i][1]][1];
        f[s[i][0]][1] = f[s[i][0]][0] + 1;
        dfs(s[i][1]);
        ans += max(now, f[s[i][1]][0]);
    }
    cout << ans << endl;
}