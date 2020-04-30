// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n ;
double p[N], dp[N];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    dp[0] = 1.0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            dp[j] = (dp[j] * (1.0-p[i]) + dp[j-1]*p[i]);
            dp[0] *= (1.0-p[i]);
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%.6f\n",f[i]);
    }
    double ans = 0.0;
    for(int i = n/2 + 1; i <= n; i++){
        ans += dp[i];
    }
    printf("%.10f",ans);
    return 0;
}