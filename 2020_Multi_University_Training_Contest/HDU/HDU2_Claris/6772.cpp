#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef unsigned long long ull;
#define lsiz(x) int(x.size())
#define lch rt << 1
#define rch rt << 1 | 1
const ll Linf = 0x7f7f7f7f7f7f7f7f;
const int Inf = 0x3f3f3f3f;
const int MAXN = 100;
char buf[100000], *p1 = buf, *p2 = buf;
inline char nc() {
    return p1 == p2 &&
                   (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
               ? EOF
               : *p1++;
}
inline ll read() {
    ll w = 1, data = 0;
    char ch = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = nc();
    if (ch == '-') w = -1, ch = nc();
    while (ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = nc();
    return w * data;
}
ll n, m, top1;
ll ans;
struct Node {
    ll k, a, b, c, d;
    bool operator<(const Node &x) const { return k < x.k; }
};
vector<vector<Node> > v;
Node ck[MAXN];
vector<Node> va, vb;
void dfs1(ll step, ll a, ll b, ll c, ll d) {
    if (step >= top1) {
        va.push_back(Node{0, a, b, c, d});
        return;
    }
    for (auto x : v[step]) dfs1(step + 1, a + x.a, b + x.b, c + x.c, d + x.d);
}
void dfs2(ll step, ll a, ll b, ll c, ll d) {
    if (step < top1) {
        vb.push_back(Node{0, a, b, c, d});
        return;
    }
    for (auto x : v[step]) dfs2(step - 1, a + x.a, b + x.b, c + x.c, d + x.d);
}
void doit() {
    n = read();
    m = read();
    ans = 0;
    v.clear();
    va.clear();
    vb.clear();
    memset(ck, 0, sizeof ck);
    vector<Node> in;
    for (ll i = 1; i <= n; i++) {
        Node temp;
        ll k = read(), a = read(), b = read(), c = read(), d = read();
        temp = Node{k, a, b, c, d};
        in.push_back(temp);
    }
    sort(in.begin(), in.end());
    vector<Node> temp;
    temp.push_back(in[0]);
    for (int i = 1; i < n; i++) {
        if (in[i].k == in[i - 1].k)
            temp.push_back(in[i]);
        else {
            v.push_back(temp);
            temp.clear();
            temp.push_back(in[i]);
        }
    }
    if (temp.size()) v.push_back(temp);
    top1 = lsiz(v) / 2;
    // cout << "lsze = " << lsiz(v) << endl;
    dfs1(0, 0, 0, 0, 0);
    dfs2(lsiz(v) - 1, 0, 0, 0, 0);
    for (auto x : va) {
        for (auto y : vb) {
            ans = max(ans, (x.a + y.a + 100) * (x.b + y.b + 100) *
                               (x.c + y.c + 100) * (x.d + y.d + 100));
            // cout << (x.a + y.a + 100) * (x.b + y.b + 100) * (x.c + y.c + 100)
            // * (x.d + y.d + 100) << endl;
        }
    }
    cout << ans << endl;
}
int main() {
    ll _ = read();
    while (_--) doit();

    return 0;
}