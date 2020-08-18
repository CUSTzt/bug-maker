#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 25;
int n, m;
char s[N], t[N];
int from[N][M], cnt[N], ans[N][M], dp[N][M];
int main() {
    memset(from, -1, sizeof(from));
    memset(dp, -1, sizeof(dp));
    scanf("%s %s", t, s);
    // s, t   -> n , m
    m = strlen(s), n = strlen(t);
    dp[0][0] = 0, from[0][0] = 0;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j && dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                from[i][j] = 0;
            }
            if (i && j && s[j - 1] == t[i - 1] &&
                dp[i - 1][j - 1] + 1 > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                from[i][j] = 1;
            }
            if (i && dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
                from[i][j] = 2;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        cnt[i - 1] = 0;
        for (int j = 0; j <= n; ++j) {
            cnt[i - 1] += !!from[i][j];
        }
        --cnt[i - 1];
    }
    for (int i = 0; i < m; ++i) {
        /*
        for (int j = i; j <= m; ++j) {
        for (int k = 0; k <= n; ++ k) {
        putchar(from[j][k] == 1 ? '\\' : ' ');
        putchar(from[j][k] == 2 ? '|' : ' ');
        }
        puts("");
        for (int k = 0; k <= n; ++ k) {
        putchar(from[j][k] == 0 ? '-' : ' ');
        putchar('*');
        }
        printf("\n");
        }
        printf("\n");
        */
        for (int j = i; j < m; ++j) {
            ans[i][j] = cnt[j];
        }
        int x = i, y = 0;
        from[i + 1][0] = 0;
        while (y <= n) {
            if (x < m && from[x + 1][y] == 2) {
                from[x + 1][y] = 0;
                --cnt[x];
                ++x;
            } else if (x < m && from[x + 1][y + 1] == 1) {
                from[x + 1][y + 1] = 0;
                --cnt[x];
                ++x, ++y;
            } else {
                ++y;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < i) {
                printf("");
            } else {
                printf("%d %c", ans[i][j], j == m - 1 ? '\n' : ' ');
            }
        }
    }
    // int tp;  
    // cin >> tp;
    // while(tp--){
    //     int l , r;
    //     cin >> l >> r;
    //     cout << (r-l+1-ans[l][r]) << endl;
    // }
}
