// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
ll fa[N], n, c[N], w[N], sum;
void init() {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) { return fa[x] == x ? fa[x] = find(fa[x]); }
void Union(int a, int b) {
    a = find(a), b = find(b);
    fa[a] = b;
}
struct Edge {
    ll v , nxt;
}e[N];
void dfs(int u ,int cur){
    c[u] = cur;
    sum += 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}