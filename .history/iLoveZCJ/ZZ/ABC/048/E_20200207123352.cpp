/**
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
|Esc|   | F1| F2| F3| F4| | F5| F6| F7| F8| | F9|F10|F11|F12| |P/S|S L|P/B|  ┌┐    ┌┐    ┌┐
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
|~ `|! 1|@ 2|# 3|$ 4|% 5|^ 6|& 7|* 8|( 9|) 0|_ -|+ =| BacSp | |Ins|Hom|PUp| |N L| / | * | - |
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
| Tab | Q | W | E | R | T | Y | U | I | O | P |[ {|] }| | \ | |Del|End|PDn| | 7 | 8 | 9 |   |
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + |
| Caps | A | S | D | F | G | H | J | K | L |; :|" '| Enter  |               | 4 | 5 | 6 |   |
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
| Shift  | Z | X | C | V | B | N | M |< ,|> .|? /|  Shift   |     | ↑ |     | 1 | 2 | 3 |   |
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E||
| Ctrl|Win |Alt |         Space         | Alt| Fn |    |Ctrl| | ← | ↓ | → | |   0   | . |←-┘|
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
**/
/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-07 11:37:38
# @Description: Think twice. Code once.
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
double x[maxn], y[maxn] , r[maxn] , dis[maxn],mp[maxn][maxn]; 
int n , vis[maxn];
double sq(double x1, double y1 , double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void SPFA(int s){
    queue<int >q;
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        vis[v] = 0;
        for(int i = 1;i < n; i++){
            if(dis[i ] > dis[v])
        }
    } 
}
int main()
{
    close;
    for(int i = 1; i < 3; i++){
        cin >> x[i] >> y[i];
    }
    r[1] = r[2] = 0;
    mp[1][2] = mp[2][1] = sq(x[1], y[1], x[2], y[2]);
    cin >> n;
    n += 2;
    for(int i = 3; i <= n; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mp[i][j] = sq(x[i], y[i], x[j], y[j]);
            mp[i][j] -= r[i] + r[j];
            if(mp[i][j] < 0)mp[i][j] = 0;
        }
    }
    SPFA(1);
    printf("%.10f\n",dis[2]);
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/