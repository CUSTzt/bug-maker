// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 16+100;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
int vis[N*N], b[N][N], n , m , ans, f[N*N];
std::vector<int> e[N*N];
int dfs(int x){
    for(auto y : e[x]){
        if(!vis[y]){
            vis[y] = 1;
            if(f[y] == -1 || dfs(f[y])){
                return f[y] = x, 1;
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while(m--){
        int x, y ;
        cin >> x >> y; --x, --y;
        b[x][y] = 1;
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!b[i][j]){
                for(int k = 0 ; k < 4; k++){
                    int xx = i + dx[k], yy = j + dy[k];
                    if(xx >= 0 && xx < n && yy >= 0 && yy < n && (!b[xx][yy])){
                        e[i*n+j].pb(xx*n + yy), e[xx*n+yy].pb(i*n+j);
                    }
                }
            }
        }
    }
    ll ans = 0;
    memset(f , 0xff, sizeof f);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i ^ j) & 1) continue; // 白色
            memset(vis , 0 , sizeof vis);
            ans += dfs(i * n + j);
        }
    }
    cout << ans << endl;
    return 0;
}