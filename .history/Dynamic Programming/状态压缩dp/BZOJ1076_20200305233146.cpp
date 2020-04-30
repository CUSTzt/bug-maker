// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 16;
int n, k, pre[1 << N], a[i] , x;
double dp[110][1 << N];
//我们可以用dp[i][j]记录第i个回合，当前状态为j时能获得的最大收益。
//如果我们正着DP，那么显然可以发现，当我们要从一个状态转移至另一个状态时，
//有可能前一个状态无法得到，因此我们要倒着推。
//dp[i][j]+=max(dp[i+1][j],dp[i+1][j|(1<<(q-1))]+a[q]);
//其中，我们要满足当前状态j满足吃掉宝物q所需的条件，然后枚举每一个符合条件的j即可。
// 注意，要判断当前状态j是否满足条件，有个很简单的方法：判断j&s[q]（s[q]存储吃掉宝物q所需的条件，
// 这里也利用了状态压缩）是否等于s[q]，如果相等，便说明j这个状态中包含了s[q]，
// 即说明当前状态满足吃掉宝物q所需的条件。
int main()
{
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while(cin >> x){
            if(x == 0)break;
            pre[i] |= (1<<(x-1));
        }
    }
    for(int i = k; i >= 1; i--){
        for(int j = 0; j < (1 << n);j++){
            for(int q = 1; q <= n; q++){
                
            }
        }
    }
    cout << dp[1][0] << endl;
    return 0;
}