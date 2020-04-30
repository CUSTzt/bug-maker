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
        if((s[0] & i) == s[0])dp[1][i] = 1;
    }
    for(int i = 1;i < n ; i++){
        for(int j = 0; j < cnt ; j++){ // ok[]
            if((s[i] & j) > s[i])continue;
            for(int k = 0; k < cnt ; k++){
                if((s[i-1]&k)>s[i-1])
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < cnt ; i++){
        ans = (ans + dp[n-1][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}