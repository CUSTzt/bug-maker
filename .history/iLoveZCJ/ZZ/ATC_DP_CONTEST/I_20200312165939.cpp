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
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            dp[j] = (dp[j] * (1.0-p[i]) + dp[i-1]*p[i]);
            dp[0] *= (1.0-p[i]);
        }
    }
    
    return 0;
}