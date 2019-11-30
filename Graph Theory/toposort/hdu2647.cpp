/****************************************************************
# @Author:      miniLCT
# @DateTime:    2019-11-06 10:14:25
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
//拓扑排序+反向建图
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 10001;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n,m;
std::vector<int >G[maxn];
int num[maxn],in[maxn],ans;
void init(){
    for(int i = 0; i <= n;i++){
        G[i].clear();
        in[i] = 0;
        num[i] = 888;
    }
}
int toposort(){
    queue<int >q;
    int cnt = 0;
    ans = 0;
    for(int i = 1;i <= n;i++){
        if(in[i] == 0)q.push(i);
    }
    while(!q.empty()){
        cnt ++;
        int u = q.front();
        ans += num[u];
        q.pop();
        for(int i = 0; i < G[u].size();i++){
            int v = G[u][i];
            if(--in[v] == 0){
                q.push(v);
                num[v] = num[u] + 1;
            }
        }
    }
    if(cnt != n)ans = -1;
    return ans;
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        init();
        while(m--){
            int u , v;
            scanf("%d%d",&u,&v);
            G[v].push_back(u);
            in[u]++;
        }
        printf("%d\n",toposort() );
    }
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
