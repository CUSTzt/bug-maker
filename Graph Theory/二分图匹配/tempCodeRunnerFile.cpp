// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 16 + 100;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
int n , m , t , vis[N][N], a[N][N], x , y, fx[N][N], fy[N][N];
bool ck(int x , int y) {
    if(x < 1 || x > n || y < 1 || y > m || a[x][y]) return 1;
    return 0;
}
int match[N*N];
int dfs(int x, int y){
    for(int i = 0; i < 8; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(ck(xx , yy)) continue;
        if(vis[xx][yy]) continue;
        vis[xx][yy] = 1;
        if(!fx[xx][yy] || dfs(fx[xx][yy], fy[xx][yy])){
            return fx[xx][yy] = x, fy[xx][yy] = y ,  1;
        }
    }return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for(int i = 0; i < t; i++){
        cin >> x >> y;
    }
    for(int i = 1; i <= t; i++){
        cin >> x >> y;
        a[x][y] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]) continue;
            if((i+j) & 1) continue;
            memset(vis , 0 , sizeof vis);
            ans += dfs(i , j);
        }
    }
    cout << n * m - t - ans << endl;
    return 0;
}