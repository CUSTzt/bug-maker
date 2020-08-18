// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5000+100, M = 300100, inf = 1 << 29;
int head[N], ver[M], edge[M], Next[M], d[N];
int n , m , s , t, maxflow, tot = 1;
// 1e4~1e5
queue<int> q;
void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
    ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}
bool bfs(){ //在残量网络上构造分层图
    memset(d , 0 , sizeof d);
    while(q.size()) q.pop();
    q.push(s); d[s] = 1;
    while(q.size()){
        int x = q.front(); q.pop();
        for(int i = head[x]; i ; i = Next[i]){
            if(!d[ver[i]] && edge[i]) {
                q.push(ver[i]); 
                d[ver[i]] = d[x] + 1;
                if(ver[i] == t) return 1;
            }
        }
    }
    return 0;
}
int dinic(int x , int flow){ // 在当前分层图上增广
    if(x == t) return flow;
    int rest = flow, k;
    for(int i = head[x]; i && rest ; i = Next[i]){
        if(edge[i] && d[ver[i]] == d[x] + 1){
            k = dinic(ver[i], min(rest , edge[i]));
            if(!k) d[ver[i]] = 0; // 剪枝  去掉增广完毕的点
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    tot = 1;
    for(int i = 1; i <= m; i++){
        int u , v, c;
        cin >> u >> v >> c;
        add(u , v, c);
    }
    int flow = 0;
    while(bfs()){
        while(flow = dinic(s, inf)) {
            maxflow += flow;
        }
    }
    cout << maxflow << endl;
    return 0;
}