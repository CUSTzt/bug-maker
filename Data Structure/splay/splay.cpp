//https://ac.nowcoder.com/acm/contest/view-submission?submissionId=43185865
namespace BST {
#define par(x) (a[x].fa)
#define lch(x) (a[x].ch[0])
#define rch(x) (a[x].ch[1])
    int root, totNode;
    struct node {
        int fa, ch[2], siz;
        bool rev;
        char c;
    }a[N];
    inline int creNode(char c) {
        a[++totNode].c = c, a[totNode].siz = 1;
        return totNode;
    }
    inline void link(int u, int f, bool ind) { par(u) = f, a[f].ch[ind] = u; }
    inline void update(int u) { a[u].siz = a[lch(u)].siz + 1 + a[rch(u)].siz; }
    inline void pushr(int u) { swap(a[u].ch[0], a[u].ch[1]), a[u].rev = !a[u].rev; }
    inline void pushdown(int u) {
        if(a[u].rev) {
            if(lch(u)) pushr(lch(u));
            if(rch(u)) pushr(rch(u));
            a[u].rev = 0;
        }
    }
    inline int build(int l, int r) {
        if(l >= r) {
            if(l > r) return 0;
            return creNode(s[l]);
        }
        int mid = l + r >> 1, u = creNode(s[mid]);
        link(build(l, mid - 1), u, 0);
        link(build(mid + 1, r), u, 1);
        update(u);
        return u;
    }
    inline void rotate(int u) {
        int f = par(u), g = par(f); bool ind = (rch(f) == u);
        link(a[u].ch[!ind], f, ind), link(f, u, !ind), link(u, g, rch(g) == f);
        update(f);
    }
    inline void splay(int u, int tar = 0) {
        int f, g;
        while((f = par(u)) != tar) {
            g = par(f);
            if(g != tar) rotate((rch(g) == f) ^ (rch(f) == u) ? u : f);
            rotate(u);
        }
        if(!tar) root = u;
        update(u);
    }
    inline int queryNum(int rem) {
        int u = root;
        while(true) {
            pushdown(u);
            if(a[lch(u)].siz >= rem) u = lch(u);
            else if(a[lch(u)].siz + 1 >= rem) return u;
            else rem -= a[lch(u)].siz + 1, u = rch(u);
        }
    }
    inline int split(int l, int r) {
        int lp = queryNum(l), rp = queryNum(r + 2);
        splay(lp), splay(rp, lp);
        return lch(rp);
    }
    inline void reverse(int l, int r) { pushr(split(l, r)); }
#undef par
#undef lch
#undef rch
} using namespace BST;