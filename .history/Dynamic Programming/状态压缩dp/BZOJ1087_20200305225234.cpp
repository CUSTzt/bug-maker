// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , k, num[1 << 10];
ll dp[10][1<<10][1<<10], ans;
bool flag[1 << 10];
void pre(){
    for(int i = 0; i < (1 << n); i++){
        if((i & (i << 1)) == 0){
            flag[i] = 1;
            num[i] = __builtin_popcount(i);
            dp[1][num[i]][i] = 1;
        }
    }
}
//dp[i][j][k]为前i行已经放了j个国王并且第i行的状态为k（二进制）的方案数，
//那么dp[i][j][k] = Σdp[i-1][j - num[k]][p],
//其中num数组记录着一行为状态k的放的国王的数目，p为上一行符合要求的状态.
int main()
{
    cin >> n >> k;

    pre();
    for(int i = 2; i <= n ; i++){
        for(int j = 0; j <= k; j++){
            for(int now = 0; now < (1 << n); now++){
                if(!flag[now])continue;
                if(num[now] > j)continue;
                for(int last = 0; last < (1 << n); last ++){
                    if(!flag[last])continue;
                    if((last & now) || ((now << 1) & last) || ((now >> 1) & last))continue;
                    dp[i][j][now] += dp[i-1][j-num[now]][last];
                }
            }
        }
    }
    for(int i = 0; i < (1 << n ) ; i++){
        ans += dp[n][k][i];
    }
    cout << ans << endl;
    return 0;
}