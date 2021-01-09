#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using LL = long long;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
constexpr int maxn = 1e6+10;
int dx[] = {1, -1, 0 , 0};
int dy[] = {0, 0, 1 , -1};
int a[500][500], dp[500][500], r, c;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }
    auto chk = [&](int x, int y){
        if(x < 1 || x > r || y < 1 || y > c) return false;
        return true;
    };
    function<int(int , int)> dfs = [&](int x, int y){
        if(dp[x][y]) return dp[x][y];
        dp[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(chk(xx , yy) && a[xx][yy] < a[x][y]){
                dfs(xx, yy);
                dp[x][y] = max(dp[x][y], dp[xx][yy]+1);
            }
        } 
        return dp[x][y]; 
    };
    int ans = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            ans = max(ans , dfs(i , j));
        }
    }
    cout << ans << endl;
    return 0;
}