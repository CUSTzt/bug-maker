// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e3+100;
char str[N][N];
int vis[N][N];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char tmp[] = {'U','D','L','R'};
char tmpp[] = {'D','U','R','L'};
int cnt , nowx , nowy;
bool check (int x , int y ){
    
}
void bfs(){
    queue<pair<int , int > > q;
    while(q.size())q.pop();
    str[nowx][nowy] = 'X';
    q.push({nowx, nowy});
    while(!q.empty()){
        pair<int , int > pr = q.front();q.pop();
        int x = pr.ff,y = pr.ss;
        if(vis[x][y]) continue;
        cnt++;vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

        }
    }
}
int main()
{
    
    return 0;
}