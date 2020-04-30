// // She is Pretty pretty!
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ff first
// #define ss second
// #define mp make_pair
// #define pb push_back

// const int N = 1e6+100;

// int len , a[15];
// ll dp[15][15], l , r, ans;

// ll dfs(int pos , int pre , int st , int limit
// ){//pos当前位置,pre前一位数,st判断前面是否全是0,limit最高位限制
//     if(pos > len )return 1;
// }
// int main()
// {

//     return 0;
//  }
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[15][15], ans;  // dp[i][j]表示搜到第i位，前一位是j，的！limit方案totnum；
int a[15], len;
long long L, R;
ll dfs(
    int pos, int pre, int st,
    int limit)  // pos当前位置,pre前一位数,st判断前面是否全是0,limit最高位限制
{
    if (pos > len) return 1;  //搜完了
    if (!limit && dp[pos][pre] != -1)
        return dp[pos][pre];  //没有最高位限制，已经搜过了
    ll ret = 0;
    int res = limit ? a[len - pos + 1] : 9;  //当前位最大数字
    for (int i = 0; i <= res; i++)           //从0枚举到最大数字
    {
        if (abs(i - pre) < 2) continue;  //不符合题意，继续
        if (st && i == 0)
            ret += dfs(pos + 1, -2, 1,
                       limit && i == res);  //如果有前导0，下一位随意
        else
            ret += dfs(pos + 1, i, 0,
                       limit && i == res);  //如果没有前导0，继续按部就班地搜
    }
    if (!limit && !st)
        dp[pos][pre] = ret;  //没有最高位限制且没有前导0时记录结果
    return ret;
}
ll part(ll x) {
    len = 0;
    while (x) a[++len] = x % 10, x /= 10;
    memset(dp, -1, sizeof dp);
    return ans = dfs(1, -2, 1, 1);
}
int main() {
    scanf("%lld%lld", &L, &R);
    // part(L - 1);
    // ll minn = ans;
    // part(R);
    // ll maxx = ans;
    printf("%lld", par - minn);
    return 0;
}