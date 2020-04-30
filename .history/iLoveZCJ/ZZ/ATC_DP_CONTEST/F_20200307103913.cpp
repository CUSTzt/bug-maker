#include <bits/stdc++.h>
using namespace std;
int dp[3005][3005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b, t = "";
    cin >> a >> b;
    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    int i = a.size(), j = b.size();
    while (dp[i][j])
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else if (dp[i][j] > dp[i - 1][j - 1])
            i--, j--, t += a[i];
    }
    reverse(t.begin(), t.end());
    cout << t;
}
