//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef unsigned long long ull;
#define lsiz(x) int(x.size())
#define lch rt<<1
#define rch rt<<1|1
const ll Linf = 0x7f7f7f7f7f7f7f7f;
const int Inf = 0x3f3f3f3f;
const int MAXN = 4e6;
char buf[100000],*p1=buf,*p2=buf;
inline char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    int w = 1, data = 0; char ch = 0;
    while(ch != '-' && (ch < '0' || ch > '9')) ch = nc();
    if(ch == '-') w = -1, ch = nc();
    while(ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = nc();
    return w * data;
}
struct Node {
    int u, v, w;
}node[MAXN];
namespace LinkCutTree {
    int fa[MAXN], val[MAXN], ch[MAXN][2];
    int rev[MAXN], st[MAXN], mi[MAXN], pos[MAXN];
    void PushUp(int x) {
        mi[x] = pos[x];
        if(ch[x][0] && node[mi[x]].w > node[mi[ch[x][0]]].w) mi[x] = mi[ch[x][0]];
        if(ch[x][1] && node[mi[x]].w > node[mi[ch[x][1]]].w) mi[x] = mi[ch[x][1]];
    }
    void Rev(int x) {
        swap(ch[x][0], ch[x][1]);
        rev[x] ^= 1;
    }
    void PushDown(int x) {
        if(rev[x]) {
            if(ch[x][0]) Rev(ch[x][0]);
            if(ch[x][1]) Rev(ch[x][1]);
            rev[x] ^= 1;
        }
    }
    bool nroot(int x) {
        return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
    }
    void rotate(int x) {
        int y = fa[x], z = fa[y], k = ch[y][1] == x, w = ch[x][!k];
        if(nroot(y)) ch[z][ch[z][1]==y] = x;
        ch[x][!k] = y; ch[y][k] = w;
        if(w) fa[w] = y;
        fa[x] = z; fa[y] = x;
        PushUp(y); PushUp(x);
    }

    void Splay(int x) {
        int y = x, top = 0;
        st[++top] = y;
        while(nroot(y)) st[++top] = fa[y], y = fa[y];
        while(top) PushDown(st[top--]);
        while(nroot(x)) {
            int y = fa[x], z = fa[y];
            if(nroot(y)) rotate((ch[z][0] == y) ^ (ch[y][0] == x) ? x : y);
            rotate(x);
        }
        PushUp(x);
    }
    void access(int x) {
        for(int y = 0; x; y = x, x = fa[x])
            Splay(x), ch[x][1] = y, PushUp(x);
    }
    void makeRoot(int x) {
        access(x); Splay(x); Rev(x);
    }
    int findRoot(int x) {
        access(x); Splay(x);
        while(ch[x][0]) PushDown(x), x = ch[x][0];
        Splay(x);
        return x;
    }
    void split(int x, int y) {
        makeRoot(x); access(y); Splay(y);
    }
    void link(int x, int y) {
        makeRoot(x);
        if(findRoot(y) != x) fa[x] = y;
    }
    void cut(int x, int y) {
        makeRoot(x);
        if(findRoot(y) == x && fa[y] == x && !ch[y][0])
            fa[y] = ch[x][1] = 0, PushUp(x);
    }
    bool check(int x, int y) {
        makeRoot(x);
        return findRoot(y) == x;
    }
}
int n, m, q, idx;


int L,R;

int que[MAXN];
void doit() {
    vector<PII> vec;
    n = read(); m = read(); q = read(); idx = n;
    for(int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = i;
        node[++idx] = {u, v, w};
    }
    for(int i = 1; i <= idx; i++) LinkCutTree::pos[i] = i;
    for(int i = 0; i <= n; i++) node[i].w = Inf;
    for(int i = n+1; i <= idx; i++) {
        int u = node[i].u, v = node[i].v;
        if(!LinkCutTree::check(u, v)) {
            LinkCutTree::link(u, i);
            LinkCutTree::link(v, i);
        }else {
            LinkCutTree::split(u, v);
            int pos = LinkCutTree::mi[v];
            vec.push_back(make_pair(pos-n, i-n));
            LinkCutTree::cut(pos, node[pos].u);
            LinkCutTree::cut(pos, node[pos].v);
            LinkCutTree::link(u, i);
            LinkCutTree::link(v, i);
        }
    }
    // memset(que, 0x3f, sizeof que);
    for(int i = 0; i <= )
    for(auto it:vec){
        L=it.first,R=it.second;
        que[L] = min(que[L], R);
    }
    for(int i = m, te = Inf; i >= 1; i--)
        te = min(te, que[i]), que[i] = min(que[i], te);
    int pre=0;
    while(q--){
        int l=read(),r=read();
        int k1=(pre^l)%m+1,k2=(pre^r)%m+1;
        L=min(k1,k2),R=max(k1,k2);
        int vis = que[L] <= R;
        cout<<(vis?"Yes":"No")<<endl;
        if(vis) pre = 1;
        else pre = 0;

    }
}
int main() {
    int _ = read(); while(_--) doit();
    return 0;
}