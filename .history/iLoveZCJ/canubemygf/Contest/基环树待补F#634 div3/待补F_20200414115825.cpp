// She is Pretty pretty!
// others
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
// #define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
string c[N], mp[N];
int n, m, vis[N], cnt[N], ans, res, incyc[N];
vector<int> G[N], rG[N], black;
void add_edge(int u, int v) {
    G[u].pb(v);
    rG[v].pb(u);
}
int get_id(int x, int y) { return x * m + y; }
int is_black(int id) {
    int x = id / m;
    int y = id % m;
    if (c[x][y] == '0') return true;
    return false;
}
void solve(int id) {
    int tot = 0, cur = 0, cyc = 0;
    black.clear();
    while (1) {
        if (vis[id] != 1) {
            cyc = tot + 1 - vis[id];
            cur = id;
            break;
        }
        vis[id] = ++tot;
        id = G[id][0];
    }
    for (int i = 0; i < cyc; i++) {
        cnt[i] = 0;
    }
    tot = 0;
    queue<int> que;
    int tmp = cur;
    while (cur!=tmp) {
		vis[cur] = tot++;
    }
}
void up() {
    cin >> n >> m;
    ans = res = 0;
    for (int i = 0; i <= n * m + 2; i++)
        vis[i] = -1, incyc[i] = 0, G[i].clear(), rG[i].clear();
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'L') {
                add_edge(get_id(i, j), get_id(i, j - 1));
            } else if (mp[i][j] == 'R') {
                add_edge(get_id(i, j), get_id(i, j + 1));
            } else if (mp[i][j] == 'U') {
                add_edge(get_id(i, j), get_id(i - 1, j));
            } else {
                add_edge(get_id(i, j), get_id(i + 1, j));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id = get_id(i, j);
            if (!(~vis[id])) solve(id);
        }
    }
    cout << ans << " " << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}