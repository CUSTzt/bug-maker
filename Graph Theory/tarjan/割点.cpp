// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 10;
struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N],tot;
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}

int dfn[N], low[N], stack[N];
int n , m, num , root;
bool cut[N];
void tarjan(int x){
    dfn[x] = low[x] = ++num;
    int flag = 0;
    for(int i = head[x]; i ; i = edge[i].nxt){
        int y = edge[i].to;
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if(low[y] >= dfn[x]){
                flag++;
                if(x != root || flag > 1)cut[x] = 1;
            }
        }else {
            low[x] = min(low[x], dfn[y]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int x, y;
    tot = 1;
    for(int i  = 1; i <= m; i++){
        cin >> x >> y;
        if(x == y)continue;
        add_edge(x , y , 1);
        add_edge(y , x, 1);
    }
    set<int> CUT;
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) root = i, tarjan(i);
    }
    for(int i = 1; i <= n; i++){
        if(cut[i])CUT.insert(i);
    }
    cout << CUT.size() << endl;
    for(auto &x : CUT){
        cout << x << ' ';
    }
    return 0;
}