// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , m, a[15][15], vis[15][15][5];
int stx, sty , edx , edy, renx, reny;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
struct node
{
    int hex, hey, renx , reny , pos, step;
    /* data */
}now;

void up() {
    memset(vis, 0 , sizeof vis);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                stx = i, sty = j;
            }
            if(a[i][j] == 3){
                edx = i, edy = j;
            }
            if(a[i][j] == 4){
                renx = i,reny = j;
            }
        }
    }
    now.hex = stx, now.hey = sty,now.renx = renx,now.reny = reny,now.step = 0;
    queue<node> q;
    int fl = 0, ans = -1;
    while(!q.empty()){
        now = q.front();
        q.pop();
        if(now.hex == edx && now.hey == edy){
            fl = 1;ans = now.step;break;
        }
        node new_;
        for(int i = 0; i < 4; i++){
            int xx = now.hex + dx[i], yy = now.hey + dy[i];
            
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}