// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1<<10;
int dp[2][N], n , k , x, zz;
int main()
{
    //oters
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++){
        int pp;
        cin >> pp;
        dp[0][pp]++;
    }
    int now = 0, pre = 1;
    while(k--){
        now ^= 1;
        pre ^= 1;
        memset(dp[now], 0 , sizeof dp[now]);
        int sum = 0;
        for(int i = 0; i < N;i++){
            dp[now][i] += (dp[pre][i] + sum % 2) / 2;
            
        }
    }
    return 0;
}