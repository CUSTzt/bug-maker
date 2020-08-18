// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 111+50;
int n , m, a[N][N][2], match[N*N], ans, vis[N*N];
char s[N][N];
vector<int> e[N*N];

int dfs(int x){
    for(auto y : e[x]){
        if(!vis[y]){
            vis[y] = 1;
            if(!match[y] || dfs(match[y])){
                return match[y] = x , 1;
            }
        }
    }return 0;
}
int tot = 1;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m+1; j++){
            if(s[i][j] == '*') a[i][j][0] = tot;
            else tot++;
        }
    }
    int t = tot;
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n+1; i++){
            if(s[i][j] == '*') a[i][j][1] = tot;
            else ++tot;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '*'){
                e[a[i][j][0]].pb(a[i][j][1]);
                e[a[i][j][1]].pb(a[i][j][0]);
            }
        }
    }
    for(int i = 1; i < t; i++){
        memset(vis , 0 , sizeof vis);
        ans += dfs(i);
    }
    cout << ans << endl;
    return 0;
}