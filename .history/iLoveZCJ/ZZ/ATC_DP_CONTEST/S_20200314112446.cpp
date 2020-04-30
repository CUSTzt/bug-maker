// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

//ÊýÎ»dp
const int N = 1e5+100;
const int mod = 1e9+7;
char a[N];
ll k,dp[N][105];
ll dfs(int len, int pre, int top){
    if(!len) return pre == 0;
    if(!top && dp[len][pre] != -1)return dp[len][pre];
    int up = top ?a[len] : 9;
    ll ret = 0;
    for(int i = 0; i <= up; i++){
        ret += dfs(len - 1,(pre+i)%)
    }
}
int main()
{
    memset(dp , -1 , sizeof dp);
    
    return 0;
}