#include <bits/stdc++.h>

using namespace std;
const int N = 2000010;
const int INF = 0x3f3f3f3f;
int n, ans[10][10];
char s[N];
int g[10][10];
int solve(int x, int y) {
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < 10; ++i) {
        int j = (i + x) % 10;
        int k = (i + y) % 10;
        g[i][j] = g[i][k] = 1;
    }
    for (int k = 0; k < 10; ++k)
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    int u = 0, ans = 0;
    for (int i = 2; i <= n; ++i) {
        int nxt = s[i] - '0';
        if (g[u][nxt] == INF) return -1;
        ans += g[u][nxt] - 1;
        u = nxt;
    }
    return ans;
}

int main() {
    scanf("%s", s + 1);
    n = (int)strlen(s + 1);
    for (int x = 0; x < 10; ++x)
        for (int y = 0; y <= x; ++y) ans[x][y] = ans[y][x] = solve(x, y);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) printf("%d ", ans[i][j]);
        cout << endl;
    }
    return 0;
}
