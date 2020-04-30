// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 16;
int n, k, pre[1 << N], a[i], x;
double dp[110][1 << N];
int main()
{
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (cin >> x)
        {
            if (x == 0)
                break;
            pre[i] |= (1 << (x - 1));
        }
    }
    for (int i = k; i >= 1; i--)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            for (int q = 1; q <= n; q++)
            {
                if ((j & pre[q]) == pre[q])
                    dp[i][j] += max(1.0*dp[i + 1][j], dp[i + 1][j | (1 << (q - 1))] + 1.0 * a[q]); // 满足条件
                else
                    dp[i][j] += dp[i + 1][j];
            }
            dp[i][j] /= n; //由于每种情况的概率是1 / n，所以要除以n
        }
    }
    cout << dp[1][0] << endl;
    return 0;
}