// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 200, maxn = 200, INF = 0x3f3f3f3f;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int t, n, m;
char s[maxn][maxn];
int k, stx, sty, edx, edy, zw[maxn][maxn];
int fl;
int chk(int x, int y) {
    if (x >= 1 && x <= m && y >= 1 && y <= n) return 1;
    return 0;
}

void dfs(int x, int y, int now) {
    if (x == edx && y == edy) {
        if (zw[x][y] <= k) {
            fl = 1;
            return;
        }
    }
    if (zw[x][y] >= k) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!chk(xx, yy)) continue;
        if (s[xx][yy] == '*') continue;
        if (zw[xx][yy] <= zw[x][y]) continue;
        // if(now == -1)zw[xx][yy] = 0;
        if (now != -1 && i != now) {
            zw[xx][yy] = zw[x][y] + 1;
        } else {
            zw[xx][yy] = min(zw[xx][yy], zw[x][y]);
        }
        dfs(xx, yy, i);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        memset(zw, INF, sizeof zw);
        cin >> m >> n;
        for (int i = 1; i <= n; i++) {
            cin >> (s[i] + 1);
        }
        cin >> k >>  sty >> stx >> edy >> edx;
        zw[stx][sty] = 0;
        fl = 0;
        dfs(stx, sty, -1);
        // cout << "zw === " << zw[edx][edy] << endl;
        puts(fl ? "yes" : "no");
    }
    return 0;
}