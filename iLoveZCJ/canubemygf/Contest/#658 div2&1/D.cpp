#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int n, t;
int p[maxn * 2];
int cnt[2];
int dp[2 * maxn] = {0};
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) scanf("%d", &p[i]);
        int f = 0;
        vector<int> tot;
        for (int i = 1; i <= 2 * n; i++) {
            int j;
            for (j = i; j <= 2 * n; j++)
                if (p[j] > p[i]) break;
            tot.push_back(j - i);
            i = j - 1;
        }
        f = 0;
        for (int i = 0; i <= 2 * n; i++) dp[i] = 0;
        for (int i = 0; i < tot.size(); i++) {
            for (int j = n; j >= tot[i]; j--)
                dp[j] = max(dp[j], dp[j - tot[i]] + tot[i]);
        }
        if (dp[n] == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
}