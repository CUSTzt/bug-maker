#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1100,MOD=1e9+7;
int dp[N][3][3],a[N];

signed main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--) {
        int n, s; cin >> n >> s;
        for (int i = 1; i <= n; ++i)cin >> a[i];
        memset(dp, 0, sizeof dp);
        dp[0][0][0]=1;
        for (int i = 1; i <= n; ++i)
            for (int j = s; j >= 0; --j)
                for (int l = 2; l >= 0; --l)
                    for (int r = 2; r >= 0; --r) {
                        int tmp = 0;
                        if (j >= a[i])tmp = (tmp + dp[j - a[i]][l][r]) % MOD;
                        if (l && j >= a[i])tmp = (tmp + dp[j - a[i]][l - 1][r]) % MOD;
                        if (r)tmp = (tmp + dp[j][l][r - 1]) % MOD;
                        dp[j][l][r] = (dp[j][l][r] + tmp) % MOD;
                    }
        int ans=0;
        for(int i=1;i<=s;++i)ans=(ans+dp[i][2][2])%MOD;
        cout<<ans*4%MOD<<endl;
    }
    return 0;
}
