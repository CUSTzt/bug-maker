// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
struct node
{
    int x, y;
    /* data */
}now;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int stx , sty , edx , edy, n , m, a[15][15] , sj[15][15], sx[15][15]; 
int chk(int x, int y){
    if(x <= n && x >= 1 && y >= 1 && y <= m)return 1;
    return 0;
}
void up() {
    memset(a, 0, sizeof a);
    memset(sj, 0, sizeof sj);
    memset(sx, 0 , sizeof sx);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                stx = i, sty = j;
                sx[stx][sty] = 6;
                sj[stx][sty] = 0;
            }
            if(a[i][j] == 3){
                edx = i , edy = j;
            }
        }
    }
    queue<node> q;
    now = {stx,sty};
    q.push(now);
    while(!q.empty()){
        now = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            int xx = now.x + dx[i] , yy = now.y + dy[i];
            if(!chk(xx, yy))continue;
            if(a[xx][yy] == 0)continue;
            if(sx[xx][yy] < sx[now.x][now.y] - 1 && sx[now.x][now.y] > 1){
                sx[xx][yy] = sx[now.x][now.y] - 1;
                sj[xx][yy] = sj[now.x][now.y] + 1;
                if(a[xx][yy] == 4){
                    sx[xx][yy] = 6;
                }
                q.push({xx,yy});
            }
        }
        if(sj[edx][edy]){
            break ;
        }
    }
    if(sj[edx][edy]){
        cout << sj[edx][edy] << endl;
    }else {
        cout << -1 << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}