// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

int n , m, dp[N];
map<pair<int , int > , int > zz;
int DP(int i){
    if(dp[i])return dp[i];
    for(int j = 0; j < n; j++){
        if(zz.count({i ,  j})){
            dp[i] = max(dp[i], DP(j)+1);
        }
    }
    return dp[i];
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u , v;
        cin >> u >> v;
        zz[{u , v}]++;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans , dp[i]);
    }
    return 0;
}