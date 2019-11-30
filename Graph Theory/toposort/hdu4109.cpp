 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年11月20日 星期三 14时59分29秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
#include<bits/stdc++.h>
//toposort
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
struct node{
    int to, val ;
};
vector<node> G[maxn];
int d[maxn], deg[maxn], n ,m;
void topo(){
    queue<int>q;
    for(int i = 0; i < n;i++){
        if(deg[i] == 0){
            q.push(i);
            d[i] = 1;
        }
    }
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i = 0; i < G[tmp].size();i++){
            int v = G[tmp][i].to;
            int w = G[tmp][i].val;
            deg[v]--;
            d[v] = max(d[v], d[tmp]+w);
            if(deg[v] == 0)
                q.push(v);
        }
    }
}
int main(){
    close;
    #ifdef miniLCT
    freopen("in.txt","r",stdin);
    #endif
    while(cin >> n >> m){
    for(int i = 0; i < n;i++){
        G[i].clear();
        deg[i] = d[i] = 0;
    }
    for(int i = 0; i < m;i++){
        int u ,v , w;
        cin >> u >> v >> w;
        G[u].push_back((node){v, w});
        deg[v]++;
    }
    topo();
    int ans = *max_element(d, d + n);
    cout << ans << endl;
    }
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
