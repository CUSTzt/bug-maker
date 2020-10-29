#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long

using namespace std;

const int N = 1010;
const int mod = 1e9 + 7;

struct node {
    int x, y;
    node() {}
    node(int xx, int yy) : x(xx), y(yy) {}
};

int m, n;
int a[N][N], dp[5][N][N], in[N][N], out[N][N];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool valid(int x, int y) {
    if (x < 1 || y < 1 || x > m || y > n)
        return false;
    else
        return true;
}

void Add(int i, int j, int x, int y) {
    dp[2][x][y] = (dp[2][x][y] + dp[1][i][j]) % mod;
    dp[3][x][y] = (dp[3][x][y] + dp[2][i][j]) % mod;
    dp[4][x][y] = (dp[4][x][y] + dp[3][i][j] + dp[4][i][j]) % mod;
}
int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    queue<node> Q;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 4; k++) {
                int tx = i + dir[k][0];
                int ty = j + dir[k][1];
                if (valid(tx, ty) == 0) continue;
                if (a[tx][ty] == a[i][j] + 1) out[i][j]++;
                if (a[tx][ty] == a[i][j] - 1) in[i][j]++;
            }
            if (in[i][j] == 0) {
                Q.push(node(i, j));
                dp[1][i][j]++;
            }
        }
    }

    node p;
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int tx = p.x + dir[k][0];
            int ty = p.y + dir[k][1];
            if (valid(tx, ty) == 0) continue;
            if (a[tx][ty] != a[p.x][p.y] + 1) continue;
            Add(p.x, p.y, tx, ty);
            in[tx][ty]--;
            if (in[tx][ty] == 0) Q.push(node(tx, ty));
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (out[i][j] == 0) ans = (ans + dp[4][i][j]) % mod;
        }
    }
    printf("%d", ans);
    return 0;
}