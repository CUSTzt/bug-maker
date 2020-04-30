/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 10:52:32
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 1e6;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , m ;
vector<pair<int , int > >edges;
vector<vector<int> >e;
vector<int >dep, par, f;
vector<tuple<int , int , int > > passengers;
void dfs(int u){
    for(int v : e[u]){
        if(v != par[u]){
            dep[v] = dep[u] + 1;
            par[v] = u;
            dfs(v);
        }
    }
}
void cover(int u , int v , int w){
    while(u != v){
        if(dep[u] < dep[v]){
            f[v] = max(f[v], w);
            v = par[v];
        } else {
            f[u] = max(f[u], w);
            u = par[u];
        }
    }
}
int queryMin(int u , int v){
    int w = 1000000;
    while(u != v){
        if(dep[u] < dep[v]){
            w = max(f[v], w);
            v = par[v];
        } else {
            w = max(f[u], w);
            u = par[u];
        }
    }
    return w;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n ;
    edges.resize(n - 1);
    e.resize(n);
    dep.resize(n);
    par.resize(n);
    f.assign(n , 1);
    for(int i = 0; i < n-1 ; i++){
        int u , v;
        cin >> u >> v;
        --u,--v;
        edges[i] = {u , v};
        e[u].emplace_back(v);e[v].emplace_back(u);
    }
    par[0] = -1;
    dfs(0);
    cin >> m;
    passengers.resize
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/