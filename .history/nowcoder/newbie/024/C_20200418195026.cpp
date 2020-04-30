#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c)         \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET    \
    int ___T;    \
    cin >> ___T; \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}

class SegmentTree {
#define lson (p << 1)
#define rson (p << 1 | 1)
#define mid (l + r >> 1)
   private:
    int size;
    struct _SegmentTree {
        long long sum = 0, lazy = 0;
    };
    _SegmentTree *s = NULL;

    void _push_up(int p) { s[p].sum = s[lson].sum + s[rson].sum; }

    void _push_down(int p, int l, int r) {
        if (s[p].lazy) {
            s[lson].sum += s[p].lazy * (mid - l + 1);
            s[rson].sum += s[p].lazy * (r - mid);
            s[lson].lazy += s[p].lazy;
            s[rson].lazy += s[p].lazy;
            s[p].lazy = 0;
        }
    }

    void _build(int p, int l, int r, long long a[]) {
        if (l == r) {
            s[p].sum = a[l];
            return;
        }
        _build(lson, l, mid, a);
        _build(rson, mid + 1, r, a);
        _push_up(p);
    }

    void _add(int p, int l, int r, int L, int R, long long c) {
        if (L <= l && r <= R) {
            s[p].sum += (r - l + 1) * c;
            s[p].lazy += c;
            return;
        }
        _push_down(p, l, r);
        if (L <= mid) _add(lson, l, mid, L, R, c);
        if (mid < R) _add(rson, mid + 1, r, L, R, c);
        _push_up(p);
    }

    long long _query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return s[p].sum;
        }
        _push_down(p, l, r);
        long long Re = 0;
        if (L <= mid) Re += _query(lson, l, mid, L, R);
        if (mid < R) Re += _query(rson, mid + 1, r, L, R);
        return Re;
    }

   public:
    void add(int L, int R, int c) { _add(1, 1, size, L, R, c); }

    long long query(int L, int R) { return _query(1, 1, size, L, R); }

    SegmentTree(int _size, long long a[]) {
        size = _size;
        s = new _SegmentTree[size << 2];
        _build(1, 1, size, a);
    }
#undef lson
#undef rson
#undef mid
};
SegmentTree *seg = NULL;

struct Edge;

struct Node {
    Edge *head = NULL;
    Node *fa = NULL;
    //	 *link_top = NULL,
    //	 *heavy_son = NULL;
    int dep = 0, value = 0, dfn = 0, size = 0;
} node[MAXN];

struct Edge {
    Edge *next = NULL;
    Node *to = NULL;

    Edge(Node *u, Node *v) {
        next = u->head;
        u->head = this;
        to = v;
    }
};

long long Dfn_array[MAXN];

void DFS1(Node *u) {
    u->size = 1;
    for (Edge *e = u->head; e != NULL; e = e->next) {
        if (e->to != u->fa) {
            e->to->fa = u;
            e->to->dep = u->dep + 1;
            DFS1(e->to);
            u->size += e->to->size;
            //	if (u -> heavy_son == NULL || e -> to -> size > u -> heavy_son
            //-> size) { 		u -> heavy_son = e -> to;
            //	}
        }
    }
}

void DFS2(Node *u) {
    static int DFN = 0;
    Dfn_array[u->dfn = ++DFN] = u->value;
    for (Edge *e = u->head; e != NULL; e = e->next)
        if (e->to != u->fa)  //&& e -> to != u -> heavy_son)
            DFS2(e->to);
}
void addroad(Node *x, Node *y, long long z) {
    if (x->dfn > y->dfn) swap(x, y);
    seg->add(x->dfn, y->dfn, z);
}

long long querysubtree(Node *x) {
    return seg->query(x->dfn, x->dfn + x->size - 1);
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    FOR(i, 1, N + 1) { cin >> node[i].value; }
    FOR(i, 1, N) {
        int a, b;
        cin >> a >> b;
        new Edge(&node[a], &node[b]);
        new Edge(&node[b], &node[a]);
    }
    DFS1(&node[R]);
    DFS2(&node[R]);
    seg = new SegmentTree(N, Dfn_array);
    for (long long i = 1; i <= M; ++i) {
        int c, x, y;
        cin >> c >> x;
        switch (c) {
            case 1:
                cin >> y;
                addroad(&node[x], &node[x], y);
                break;
            case 2:
                cout << querysubtree(&node[x]) << '\n';
                break;
        }
    }
    return 0;
}
