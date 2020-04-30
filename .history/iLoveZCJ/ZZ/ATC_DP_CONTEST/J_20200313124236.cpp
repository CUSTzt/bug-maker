// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 310;
int a[4], x, n;
double dp[N][N][N];
double dfs(int i , int j , int k){
    if(dp[i][j][k])return dp[i][j][k];
    if(i + j + k == 0) return 0;
    double ans = 1;
    if(i)ans += dfs(i - 1, j , k) * i / 
}
int main()
{
    cin >> n;
    while(n--){
        cin >> x;
        a[x]++;
    }
    cout << dfs(a[1],a[2],a[3]);
    return 0;
}