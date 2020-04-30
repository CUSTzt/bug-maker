// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

namespace UndirectedGraph
{
int n, m, i, d[N], g[N], v[N << 1], vis[N << 1], nxt[N << 1], ed, w[N << 1];
int ans[N], cnt;
void add(int x, int y, int z)
{
    d[x]++;
    v[++ed] = y;
    w[ed] = z;
    nxt[ed] = g[x];
    g[x] = ed;
}
void dfs(int x){
    for(int&i=g[x];i;){
        if(vis[i]){
            i = nxt[i];
            continue;
        }
        vis[i] = vis[i^1] = 1;
        int j = w[i];
        dfs(v[i]);
        ans[++cnt] = j;
    }
}
} // namespace UndirectedGraph
const int N = 1e6 + 100;

int main()
{

    return 0;
}