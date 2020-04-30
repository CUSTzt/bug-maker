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
    if(i) ans += dfs(i - 1, j , k) * i / n;
    if(j) ans += dfs(i + 1, j - 1, k) * j / n;
    if(k) ans += dfs(i , j+1 , k-1) * k / n;
    if(i+j+k!=n)ans*=1.0*n/(j+k+i);
    return dp[i][j][k] = ans;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> x;
        a[x]++;
    }
    cout << dfs(a[1],a[2],a[3])<<'\n';
    return 0;
}