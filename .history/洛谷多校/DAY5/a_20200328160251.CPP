#include <bits/stdc++.h>
using namespace std;
int nn, mm, aa, bb, cc;
void getMinimumPenalty(string x, string y, int pxy, int pgap) {
    int i, j;  // intialising variables
    int m = x.length();  // length of gene1
    int n = y.length();  // length of gene2

    long long  dp[min(6000,n + m + 1)][min(n + m + 1,6000)] = {0};
    for (i = 0; i <= min(6000,n + m); i++) {
        dp[i][0] = i * pgap;
        dp[0][i] = i * pgap;
    }

    // calcuting the minimum penalty
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1] + pxy, dp[i - 1][j] + pgap,
                                dp[i][j - 1] + pgap});
            }
        }
    }

    int l = n + m;  
    i = m;
    j = n;
    int xpos = l;
    int ypos = l;
    int xans[l + 1], yans[l + 1];

    while (!(i == 0 || j == 0)) {
        if (x[i - 1] == y[j - 1]) {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)y[j - 1];
            i--;
            j--;
        } else if (dp[i - 1][j - 1] + pxy == dp[i][j]) {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)y[j - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] + pgap == dp[i][j]) {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)'_';
            i--;
        } else if (dp[i][j - 1] + pgap == dp[i][j]) {
            xans[xpos--] = (int)'_';
            yans[ypos--] = (int)y[j - 1];
            j--;
        }
    }
    while (xpos > 0) {
        if (i > 0)
            xans[xpos--] = (int)x[--i];
        else
            xans[xpos--] = (int)'_';
    }
    while (ypos > 0) {
        if (j > 0)
            yans[ypos--] = (int)y[--j];
        else
            yans[ypos--] = (int)'_';
    }
    int id = 1;
    for (i = l; i >= 1; i--) {
        if ((char)yans[i] == '_' && (char)xans[i] == '_') {
            id = i + 1;
            break;
        }
    }
    long long ans = 0;
    for (int i = id; i <= l; i++) {
        if ((char)xans[i] == (char)yans[i]) {
            ans += aa;
        } else if (xans[i] == '_' || yans[i] == '_') {
            ans -= cc;
        } else {
            ans -= bb;
        }
    }
    cout << ans << endl;
}
int main() {
    string gene1, gene2;
    cin >> nn >> mm >> aa >> bb >> cc;
    cin >> gene1 >> gene2;
    int misMatchPenalty = bb;
    int gapPenalty = cc;
    getMinimumPenalty(gene1, gene2, misMatchPenalty, gapPenalty);
    return 0;
}