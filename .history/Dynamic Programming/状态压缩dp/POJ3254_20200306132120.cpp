// She is Pretty pretty!
//#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 12;
const int mod = 100000000;
int n, m, dp[20][1 << N], a[20][20], s[20], ok[1 << N], cnt;
bool check(int x)
{
    if (x & (x << 1))
        return false;
    return true;
}
void pre(int n)
{
    int mt = 1 << n;
    for (int i = 0; i < mt; i++)
    {
        if (check(i))
        {
            ok[cnt++] = i;
        }
    }
}
int main()
{
    cin >> n >> m;
    pre(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                s[i] |= (a[i][j] << (m - 1 - j));
                //printf("s[%d]===%d\n", i, s[i]);
            }
        }
    }
    /* for(int i = 0; i < n;i++){
        printf("s[%d]===%d\n",i,s[i]);
    }*/
    for (int i = 0; i < cnt; i++) // 第一行
    {
        if ((s[0] | ok[i]) == s[0])
            dp[0][ok[i]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < cnt; j++)
        { // ok[]
            if ((s[i] | ok[j]) > s[i])
                continue;
            for (int k = 0; k < cnt; k++)
            {
                if ((s[i - 1] | ok[k]) > s[i - 1])
                    continue; //上一行是不是满足
                if (ok[j] & ok[k])
                    continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][ok[k]]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < cnt; i++)
    {
        ans = (ans + dp[n - 1][ok[i]]) % mod;
    }
    cout << ans << endl;
    return 0;
}1