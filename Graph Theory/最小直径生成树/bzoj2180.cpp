#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 1110;
constexpr int INF = 0x3f3f3f3f;
void umin(int &x, int y) {
    if (x > y) x = y;
}
int n, m, x, y, z;
int a[maxn][maxn], dis[maxn][maxn], rk[maxn][maxn];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    memset(a, 0x3f, sizeof a), memset(dis, 0x3f, sizeof dis);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        umin(dis[x][y], z), umin(dis[y][x], z), umin(a[x][y], z), umin(a[y][x], z);
    }
    auto folyd = [&]() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    umin(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        // rk[i][j]：i点到其它所有点最短路中第k小的是点i到点rk[i][j]
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                rk[i][j] = j;
            }
            for (int j = 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (dis[i][rk[i][k]] < dis[i][rk[i][j]])
                        swap(rk[i][j], rk[i][k]);
                }
            }
        }
    };
    folyd();
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == INF || !dis[i][j]) {
                continue;
            }
            int now = n;
            for (int k = n - 1; k >= 2; k--) {
                if (dis[i][rk[j][k]] > dis[i][rk[j][now]]) {
                    umin(ans, dis[j][rk[j][k]] + dis[i][rk[j][now]] + a[i][j]);
					now = k;			//now：保证road[i][rk[j][now]]是后缀最大的
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}