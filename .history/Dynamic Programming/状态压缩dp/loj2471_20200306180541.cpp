//others
// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define INF 0x3f3f3f3f
//#define mp make_pair
#define pb push_back
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
const int mod = 1e9+9;
const int N = 1e6+100;
map<int , int > mp;
int a[12][12],b[12][12], n , m , vis[12], w[12][12];
int dfs(int op,int hsh){
    if(mp.count(hsh))return mp[hsh];
    if(vis[n] == m )return 0;
    int ans = (op == 0)?INF:-INF;
    for(int i =1; i <= n; i++){
        if(vis[i]!=vis[i-1] && vis[i]!=m){
            
             vis[i]++;
            if (op==0) ans=min(ans,dfs(op^1,hsh^w[i][vis[i]])-b[i][vis[i]]);
            else ans=max(ans,dfs(op^1,hsh^w[i][vis[i]])+a[i][vis[i]]);
            vis[i]--;
        }
    }
    return mp[hsh]=ans
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            cin >> b[i][j];
            w[i][j] = rnd(mod);
        }
    }
    vis[1] = 1;
    cout << a[1][1] + dfs(0 , 0);
    return 0;
}