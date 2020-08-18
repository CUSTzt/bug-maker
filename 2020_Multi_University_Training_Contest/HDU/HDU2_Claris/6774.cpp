#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 35;
int nex[N][M], dp[M];
char s1[N], s2[M];
/*
预处理出nex数组
nex[i][j]表示字符串n第i个位置上下一个字符j的位置。
那么dp[i][j]表示字符串m到第i个位置上，lcs的长度为j的时候的最早的结束位置。
那么dp的第一维就可以去掉。然后枚举i的时候枚举j∈(0,i-1)，从那个位置转移过来，lcs记录一下最大值即可。
然后答案是r-l+1+m-2*lcs
*/
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%s%s", s1 + 1, s2 + 1);
        n = strlen(s1 + 1), m = strlen(s2 + 1);
        for (int i = 0; i < 26; i++) nex[n + 1][i] = n + 1;
        for (int i = n; i; i--) {
            for (int j = 0; j < 26; j++) {
                if (j == s1[i] - 'a')
                    nex[i][j] = i;
                else
                    nex[i][j] = nex[i + 1][j];
            }
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            dp[0] = l - 1;
            for (int i = 1; i <= m; i++) dp[i] = n + 1;
            int lcs = 0;
            for (int i = 1; i <= m; i++) {
                for (int j = i - 1; ~j; j--) {
                    if (dp[j] < r && nex[dp[j] + 1][s2[i] - 'a'] <= r)
                        dp[j + 1] = min(dp[j + 1], nex[dp[j] + 1][s2[i] - 'a']);
                    if (dp[j + 1] <= r) lcs = max(lcs, j + 1);
                }
            }
            printf("%d\n", r - l + 1 + m - 2 * lcs);
        }
    }
    return 0;
}
