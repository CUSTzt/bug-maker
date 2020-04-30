// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
char a[800][800],ans[800][800];
int vis[800][800];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n , m;
bool chk(int i , int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    return true;
}
void dfs(int x, int y){
    vis[x][y] = 1;
    for(int i = 0; i < 4;i++){
        int X = x+dx[i], Y =y + dy[i];
        if(vis[X][Y]){

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ans[i][j];
        }cout << endl;
    }
    return 0;
}