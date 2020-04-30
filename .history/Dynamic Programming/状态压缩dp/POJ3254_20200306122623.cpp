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
void pre()
{
    int m = 1 << N;
    for (int i = 0; i < m; i++)
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
    pre();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            s[i] |= (a[i][j] << m - 1 - i);
        }
    }
    for (int i = 0; i < cnt; i++) // 第一行
    {
        if(s[i] )
    }
    ll ans = 0;

    return 0;
}