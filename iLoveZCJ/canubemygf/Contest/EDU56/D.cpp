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
const int mod = 998244353;
int f[N];
int c1, c2, n, m, ans, color[N], fl;
vector<int> g[N];
void dfs(int u) {
    if (color[u] == 2)
        c1++;
    else
        c2++;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == u) continue;
        if (color[u] == color[v]) {
            fl = 0;
            return;
        }
        if (color[v]) continue;
        color[v] = color[u] ^ 1;
        dfs(v);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * 2 % mod;
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n + 10; i++) {
            g[i].clear();
            color[i] = 0;
        }
        ans = 1;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v), g[v].pb(u);
        }
        fl = 1;
        for (int i = 1; i <= n; i++) {
            if (!color[i]) {
                c1 = 0, c2 = 0;
                color[i] = 2;
                dfs(i);
                if (fl == 0) {
                    ans = 0;
                    break;
                } else {
                    ans = ans * ((f[c1] + f[c2]) % mod) % mod;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}