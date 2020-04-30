// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
//题意：给定一个n个点m条边的无向图，
//要求找出一个点数恰好为√n的独立集，或者找出一个点数>=√n的环（上取整）
vector<int > v[N];
int fa[N], dep[N], num[N], n , m , lim, x, y ;
void dfs(int x){
    ++num[dep[x] % (lim - 1)];
    for(auto to : v[x]){
        if(to == fa[x])continue;
        if(dep[to] == -1){
            dep[to] = dep[x] + 1;
            fa[to] = x;
            dfs(to);
        }else if(dep[x] - dep[to]>= lim - 1 ){
            cout << 2 << endl;
            cout << dep[x] - dep[to] + 1 << endl;
            for(int i = x; i != pa[])
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    memset(dep , 0xff, sizeof dep);
    lim = ceil(sqrt(1.0*n));
    dep[1] = 0;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    
    return 0;
}