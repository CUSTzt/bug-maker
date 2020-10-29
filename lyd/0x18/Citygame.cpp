#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int n, m, h[maxn], q[maxn], w[maxn];
char a[maxn][maxn];
int work() {
    int r = 0;
    h[m + 1] = 0;
    int maxv = 0;
    for (int i = 1; i <= m + 1; i++) {
        int width = 0;
        while (r && h[q[r]] >= h[i]) {
            width += w[q[r]];
            maxv = max(maxv, h[q[r]] * width);
            r--;
        }
        q[++r] = i;
        w[i] = width + 1;
    }
    return maxv;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'F') h[j] += 1;
            else h[j] = 0;
        }
        ans = max(ans, work()); //ans是最大的矩形
    }
    printf("%d", ans * 3); 
    return 0;
}