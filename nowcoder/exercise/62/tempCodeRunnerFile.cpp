// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

void up() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > vis(n + 1, vector<int>(n + 1));
    int u, v;
    int fl = 0;
    if (n >= 6) {
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
        }
        cout << "yes\n";
    } else {
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            vis[u][v] = 1;
            vis[v][u] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                for (int k = 1; k <= n; k++) {
                    if (i == k || j == k) continue;
                    if (vis[i][j] && vis[i][k] && vis[k][j]) fl = 1;
                    if (!vis[i][j] && !vis[i][k] && !vis[k][j]) fl = 1;
                }
            }
        }
        puts(fl ? "yes" : "no");
    }
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