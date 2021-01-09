// 不含前导零且相邻两个数字之差至少为2的正整数被称为windy数.求l~r之间多少个windy数字
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll dp[20][20];  // dp[i][j]表示搜到第i位，前一位是j，的！limit方案totnum；
ll l, r, a[20], ans, len;
int main() {
    cin >> l >> r;
    std::function<ll(ll, ll, ll, ll)> dfs = [&](ll pos, ll pre, ll st, ll limit) {
        // pos当前位置,pre前一位数,st判断前面是否全是0,limit最高位限制
        if (pos > len) return 1ll;  //搜完了
        if (!limit && dp[pos][pre] != -1)
            return dp[pos][pre];  //没有最高位限制，已经搜过了
        ll ret = 0ll;
        ll res = limit ? a[len - pos + 1] : 9;  //当前位最大数字
        for (int i = 0; i <= res; i++)          //从0枚举到最大数字
        {
            if (abs(i - pre) < 2) continue;  //不符合题意，继续
            if (st && i == 0)
                ret += dfs(pos + 1, -2, 1, limit && i == res);  //如果有前导0，下一位随意
            else
                ret += dfs(pos + 1, i, 0, limit && i == res);  //如果没有前导0，继续按部就班地搜
        }
        if (!limit && !st)
            dp[pos][pre] = ret;  //没有最高位限制且没有前导0时记录结果
        return ret;
    };  
    auto solve = [&](ll x) {
        len = 0;
        while (x) a[++len] = x % 10, x /= 10;
        memset(dp , -1 , sizeof dp);
        return dfs(1, -2, 1, 1);
    };
    cout << solve(r) - solve(l - 1) << endl;
}