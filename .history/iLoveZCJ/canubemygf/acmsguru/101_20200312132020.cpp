// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 10+100;

int n , x , y;
vector<int > odd, even ;
vector<pair<int , int > > E[10];
bool vis[N];
vector<int >ans;
void dfs(int x){
    while(E[x].size()){
        pair<int , int > bk = E[x].back();
        E[x].pop_back();
        if(vis[abs(bk.ss)])continue;
        vis[abs(bk.ss)] = 1;
        dfs(bk.ff);
        ans.pb(-bk.ss);
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x >> y;
        E[x].pb({y,i});
        E[y].pb({x,-i});
    }
    for(int i = 0; i < 7; i++){
        if(E[i].size() & 1){
            odd.pb(i);
        }else if(E[i].size()){
            even.pb(i);
        }
    }
    if(odd.size() == 0){
        dfs(even[0]);
        if(ans.size == n){
            for(auto )
        }
    }
    return 0;
}