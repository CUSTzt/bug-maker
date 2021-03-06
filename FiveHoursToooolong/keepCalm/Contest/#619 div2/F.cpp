// std 最短路  多源bfs
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int K = 45;
const double PI = acos(-1.0);
ll mod = 1e9+7;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
int n , m , k , r1, r2 , c1 , c2 , ans = 0, grid[maxn][maxn], cost[K][maxn][maxn];
bool vis[maxn];
int dr[] = {0 , 0, 1 ,-1};
int dc[] = {1 , -1, 0, 0};
queue<pair <int , int> > q;
vector<pair <int , int > >cells[K];
void bfs(int col){
    for(int i = 0; i < (int )cells[col].size(); i++){
        cost[col][cells[col][i].first][cells[col][i].second] = 0;
        q.push({cells[col][i].first, cells[col][i].second});
    }   
    for(int i = 1; i <=  k ; i++){
        vis[i] = false;
    }
    int r , c , nr , nc;
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        q.pop();
        if(!vis[grid[r][c]]){
            vis[grid[r][c]] = 1;
            for(int i = 0 ; i < (int )cells[grid[r][c]].size();i++){
                nr = cells[grid[r][c]][i].first;
                nc = cells[grid[r][c]][i].second;
                if(cost[col][nr][nc] == -1){
                    cost[col][nr][nc] = cost[col][r][c] + 1;
                    q.push({nr,nc}); 
                }
            }
        }
        for(int i = 0; i < 4; i++){
            nc = c + dc[i];
            nr = r + dr[i];
            if(nr >= 0 && nr < n &&nc >= 0 && nc < m && cost[col][nr][nc] == -1){
                cost[col][nr][nc] = cost[col][r][c] + 1;
                q.push({nr , nc});
            }
        }
    }
}
void input(){
    cin >> n >> m >> k;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            cin >> grid[i][j];
            cells[grid[i][j]].push_back({i , j});
        }
    }
}
int main()
{
    input();
    memset(cost , -1 , sizeof cost);
    for(int i = 1; i <= k ; i++){
        bfs(i);
    }
    CASET{
        cin >> r1 >> c1 >> r2 >> c2;
        r1--,r2--,c1--,c2--;
        ans = abs(r1 - r2 )+ abs(c1 - c2);
        for(int i = 1; i <= k ; i++){
            ans = min(ans , 1 + cost[i][r1][c1] + cost[i][r2][c2]);
        }cout << ans << endl;
    }
}