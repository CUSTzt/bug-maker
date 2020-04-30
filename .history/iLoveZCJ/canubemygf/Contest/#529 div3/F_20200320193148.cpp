// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
struct node {
    int u, v;
    ll cost;
    node() {}
    node(int u, int v, ll cost) { u = u, v = v, cost = cost; };
} edge[N];
bool cmp(const node a, const node b) { return a.cost < b.cost; }
ll n, m, V, E, a[N];
ll p[N], r[N];
void init(ll n) {
    for (ll i = 0; i < n; i++) {
        p[i] = i;
        r[i] = 0;
    }
}
ll find(ll x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = find(p[x]);
}
void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (r[x] < r[y])
        p[x] = y;
    else {
        p[y] = x;
        if (r[x] == r[y]) r[x]++;
    }
}
bool same(ll x, ll y) { return find(x) == find(y); }
ll kruskal() {
    sort(edge, edge + E, cmp);
    init(V);
    ll res = 0;
    for (ll i = 0; i < E; i++) {
        node e = edge[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}
int n, m;
ll a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll res = 0x3f3f3f3f, id = -1;
    V = n, E = 0;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < res ){
            res = a[i];
            id = i;
        }
    }
    for(ll i = 1; i <= n; i++){
        if(i == id)continue;
        
    }
    return 0;
}