// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e3+100;
ll dp[N][N];
int a[N], n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i ; j <= n; j++){//[j-i+1,j]
            int l = j - i + 1, r = j;
            dp[l][r] = max(a[l] - dp[l+1][r], a[r]-dp[l][r-1] );
            printf("dp[%d][%d]===%d\n",l,r,dp[l][r]);
        }
    }
    cout << dp[1][n] <<endl;
    return 0;
}