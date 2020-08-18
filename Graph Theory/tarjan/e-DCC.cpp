// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot;
int dfn[N], low[N], n, m, num;
bool bridge[N];
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}
void tarjan(int x, int in_edge) {
    dfn[x] = low[x] = ++num;
    int flag = 0;
    for (int i = head[x]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);

            if (low[y] > dfn[x]) bridge[i] = bridge[i ^ 1] = 1;
        } else if (i != (in_edge ^ 1)) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}
// e-dcc的求法
int c[N]; //c[x]表示节点x所属的"边双联通分量"的编号
int dcc;

void dfs(int x){
    c[x] = dcc;
    for(int i = head[x]; i ; i = edge[i].nxt){
        int y = edge[i].to;
        if(c[y] || bridge[i])continue;
        dfs(y);
    }
}

// e-DCC缩点
int hc[N], vc[N*2], nc[N*2],tc;
void add_c(int x, int y){
    vc[++tc] =y,nc[tc] = hc[x], hc[x] = tc;
}

int main() { // 正确性暂时还没验证
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y, 1);
        add_edge(y, x, 1);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i, 0);
    }
    for (int i = 2; i < tot; i += 2) {
        if (bridge[i]) {
            cout << edge[i ^ 1].to << " " << edge[i].to << endl;
        }
    }

    //e-dcc特有的
    for(int i = 1; i <= n; i++){
        if(!c[i]){
            ++dcc;
            dfs(i);
        }
    }
    printf("There are %d e-DCCs.\n",dcc);
    for(int i = 1; i <= n; i++){
        printf("%d belongs to DCC %d.\n",i,c[i]);
    }

    //e-dcc缩点
    tc = 1;
    for(int i = 2; i <= tot; i++){
        int x = edge[i ^ 1].to, y = edge[i].to; // 不确定对不对
        if(c[x] == c[y])continue;
        add_c(c[x], c[y]);
    }
    printf("缩点后的森林，点数%d,边数%d(可能有重边)\n",dcc,tc/2);
    for(int i = 2; i < tc; i+=2){
        printf("%d %d\n",vc[i^1] , vc[i]);
    }
    return 0;
}
