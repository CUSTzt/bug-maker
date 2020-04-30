// She is Pretty pretty!
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

using namespace std;
#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int n;
int a[21][21], ok[28657], cnt, sum[21][28657], dp[21][28657];
bool check(int x)
{
    if (x & (x << 1))
        return false;
    return true;
}
int get_sum(int i, int j)
{ // i行状态为j
    int res = 0;
    for (int k = 0; k < n; k++)
    {
        if ((j >> k) & 1)
            res += a[i][n - 1 - k];
    }
    return res;
}
void pre(int x)
{
    int m = 1 << x;
    cnt = 0;
    memset(dp, 0, sizeof dp);
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < m; i++)
    {
        if (check(i))
            ok[cnt++] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            sum[i][j] = get_sum(i, ok[j]);
        }
    }
}
int32_t main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        pre(n);
        for (int i = 0; i < cnt; i++)
        {
            dp[0][i] = sum[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < cnt; j++)
            {
                for (int k = 0; k < cnt; k++)
                {
                    if (ok[k] & ok[j])
                        continue;
                    else dp[i][j] = max(dp[i][j], dp[i - 1][k] + sum[i][j]);
                }
            }
        }
        int ans = dp[n-1][0];
        for (int i = 0; i < cnt; i++)
        {
            ans = max(ans, dp[n - 1][i]);
        }
        cout << ans << endl;
    }

    return 0;
}