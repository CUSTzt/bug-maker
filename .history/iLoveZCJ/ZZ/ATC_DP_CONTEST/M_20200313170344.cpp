#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define ULL unsigned long long
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-10;
const int maxn=1<<17;
const int N=1e2+10,M=1e5+100;
const int mod=1e9+7;
int dp[N][M], sum[N][M], n , k, a[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][k] = sum[0][k] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = (sum[i-1][min(k, j+a[i])] - sum[i-1][j-1] + mod) % mod;
        }
        sum[i][0] = dp[i][0] = sum[i-1][a[i]];
        for(int j = 1; j<= k; j++){
            sum[i][j] = (sum[i][j-1] + dp[i][j])% mod;
        }
    }
    cout << dp[n][0] <<endl;
    
}
/*
1
6 7
0 0 0 0 0 0
0 1 0 3 0 1
2 9 1 2 1 2
8 7 1 3 4 3
1 0 2 2 7 7
0 1 0 0 1 0
0 0 0 0 0 0
*/