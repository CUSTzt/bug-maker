#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll
map<ll, int> mp;
constexpr int N = 20, M = 5050;
vector<pair<int, int>> ans[M<<5];
int k[N], a[N][M], vis[N], s[N], G[400 * M ], dp[1<<20];
int n, cnt;
pair<int, int> p[M * N];
void go(int x) {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    vector<pair<int, int>> tp;
    int limit = (1 << p[x].first - 1) ;
    q.push(x);
    while (q.size()) {
        auto u = q.front();
        q.pop();
        if (u == x && vis[p[u].first]) {
            dp[limit] = 1, ans[limit] = tp;
            return;
        }
        if (vis[p[u].first]) return;
        vis[p[u].first] = 1;
        if (G[u]) {
            int v = G[u];
            q.push(v);
            limit |= (1 << p[v].first - 1);
            tp.push_back({a[p[v].first][p[v].second], p[u].first});
        }
    }
}
int cmp(pair<int, int>& a, pair<int, int>& b) {
    int p1 = mp[a.first], p2 = mp[b.first];
    return p[p1].first < p[p2].first;
}
int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j];
            sum += a[i][j], s[i] += a[i][j];
            // mp[a[i][j]] = ++cnt;
            mp.emplace(a[i][j], ++cnt);
            p[cnt] = {i, j};
        }
    }
    if (sum % n) {
        return cout << "No\n", 0;
    }
    // cout << "now   alive  " << endl;
    sum /= n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k[i]; j++) {
            int v = sum - (s[i] - a[i][j]);
            int cur = mp[v];
            if (!cur || (p[cur].first == i && p[cur].second != j)) continue;
            G[mp[a[i][j]]] = cur;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        go(i);
    }
    int limit = (1 << n) - 1;
    for (int i = 1; i <= limit; i++)
        if (!dp[i]) {
            for (int j = (i - 1) & i; j; j = (j - 1) & i)
                if (dp[j] && dp[i ^ j]) {
                    dp[i] = 1;
                    ans[i] = ans[j];
                    for (auto tmp : ans[i ^ j]) ans[i].push_back(tmp);
                    break;
                }
        }
    if (dp[limit] == 0) return puts("No"), 0;
    puts("Yes");
    sort(ans[limit].begin(), ans[limit].end(), cmp);
    for (auto tmp : ans[(1 << n) - 1])
        cout << tmp.first << " " << tmp.second << endl;
    return 0;
}

