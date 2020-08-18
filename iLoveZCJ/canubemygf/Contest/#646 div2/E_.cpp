// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
vector<int> g[N];
ll a[N], b[N], c[N], n, ans, to0[N], to1[N];
void add_edge(int u, int v) { g[u].pb(v), g[v].pb(u); }
void dfs(int u, int fa, ll mn) {
    mn = min(mn, a[u]);
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u, mn);
        to0[u] += to0[v], to1[u] += to1[v];
    }
    if (b[u] != c[u]) {
        if (b[u] == 1)
            to0[u]++;
        else
            to1[u]++;
    }
    if (mn == a[u]) {
        int mnn = min(to0[u], to1[u]);
        ans += 1ll*mnn * 2 * a[u];
        to0[u] -= mnn, to1[u] -= mnn;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    dfs(1, 0 , INT_MAX);
    if(to1[1] || to0[1]){
        puts("-1");
    }else cout << ans << endl;
    return 0;
}