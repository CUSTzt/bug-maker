// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
ll fa[N], n, m, c[N], w[N], sum, cnt, last[N];
void init() {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void Union(int a, int b) {
    a = find(a), b = find(b);
    fa[a] = b;
}
struct Edge {
    ll v, nxt;
} e[N];
void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].nxt = last[u], last[u] = cnt;
}
bool flag;
void dfs(int u, int cur) {
    c[u] = cur;
    sum += w[u] * cur;
    for (ll i = last[u]; i; i = e[i].nxt) {
        ll v = e[i].v;
        if (!c[v])
            dfs(v, -cur);
        else if (c[u] == c[v])
            flag = 1;
    }
}
pair<ll, ll> p[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tp;
    cin >> tp;
    while (tp--) {
        cnt = 0;
        memset(last, 0, sizeof last);
        cin >> n >> m;
        init();
        for(int i = 1; i <= n; i++){
            cin >> w[i];
            w[i] = -w[i];
            c[i] =  0;
        }
        for(int i = 1;  i <= n; i++){
            int zc;
            cin >> zc;
            w[i]+=zc;
        }
        ll edges = 0;
        for(int i = 1; i <= m; i++){
            int op, u , v;
            cin >> op >> u >> v;
            if(op==1)p[++edges] = {u,v};
            else Union(u,v);
        }
        for(int i = 1; i<= n; i++){
            if(find(i) != i)w[find(i)]+=w[i];
        }
        for(int i = 1; i <= edges; i++){
            int u = find(p[i].ff);
            int v = find(p[i].ss);
            add(u,v);add(v,u);
        }
        bool zz = false;
        
    }
    return 0;
}