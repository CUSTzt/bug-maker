#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 6000;
int a[N][N], b[N][N];
int cnt[N], f[20][N];
ll ans = 0;

int ask(int x, int y) {
    int k = cnt[y - x + 1];
    return max(f[k][x], f[k][y - (1 << k) + 1]);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 2; i < N; i++) cnt[i] = cnt[i >> 1] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) a[i][j] = i / __gcd(i, j) * j;
    for (int row = 1; row <= n; row++) {
        for (int j = 1; j <= m; j++) {
            f[0][j] = a[row][j];
        }
        for (int j = 1; j < 20; j++)
            for (int i = 1; i + (1 << j - 1) <= m; i++)
                f[j][i] = max(f[j - 1][i], f[j - 1][i + (1 << j - 1)]);
        for (int j = k; j <= m; j++) b[row][j] = ask(j - k + 1, j);
    }
    for (int row = k; row <= m; row++) {
        for (int j = 1; j <= n; j++) f[0][j] = b[j][row];
        for (int j = 1; j < 20; j++)
            for (int i = 1; i + (1 << j - 1) <= n; i++)
                f[j][i] = max(f[j - 1][i], f[j - 1][i + (1 << j - 1)]);
        for (int j = k; j <= n; j++) ans += ask(j - k + 1, j);
    }
    cout << ans << endl;
}