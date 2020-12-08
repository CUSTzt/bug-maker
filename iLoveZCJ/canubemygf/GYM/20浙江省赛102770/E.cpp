// others 
#include <bits/stdc++.h>
#define fi first
#define se second
#define mid ((l + r) >> 1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int, int> vi;
const ll mod = 1e9 + 7;
const double inf = 1e15;
const int N = 1e5 + 10;
int n, q, arr[N], rt[N], rk[N];  // m是权值的数量
pii brr[N];
struct TR {
    ll sum;
    int num, lo, ro;
} tr[N << 5];
int tr_cnt;  //之后需要初始化=0
int build(int l = 1, int r = n) {
    int o = ++tr_cnt;
    tr[o].sum = 0;
    tr[o].num = 0;
    //如果开始不是0，需要初始化，之后修改时会继承前面节点不用再初始化
    if (l != r) {
        tr[o].lo = build(l, mid);
        tr[o].ro = build(mid + 1, r);
    }
    return o;
}
int update(int p, int pre, int l = 1, int r = n) {
    int o = ++tr_cnt;
    tr[o] = tr[pre];
    tr[o].num++;  //都是+1
    tr[o].sum += brr[p].fi;
    if (l != r) {
        if (p <= mid)
            tr[o].lo = update(p, tr[o].lo, l, mid);
        else
            tr[o].ro = update(p, tr[o].ro, mid + 1, r);
    }
    return o;
}
// u和v是两个线段树的根，相减后的线段树求第k个的下标位置
ll query(int k, int u, int v, int l = 1, int r = n) {
    if (tr[v].num - tr[u].num == k) return tr[v].sum - tr[u].sum;
    int tmp = tr[tr[v].ro].num - tr[tr[u].ro].num;
    if (k > tmp) {
        ll ret = tr[tr[v].ro].sum - tr[tr[u].ro].sum;
        return ret + query(k - tmp, tr[u].lo, tr[v].lo, l, mid);
    } else {
        return query(k, tr[u].ro, tr[v].ro, mid + 1, r);
    }
}
ll base[N];
void solve() {
    tr_cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        brr[i].fi = arr[i];
        brr[i].se = i;
    }
    sort(brr + 1, brr + 1 + n);
    for (int i = 1; i <= n; i++) rk[brr[i].se] = i;
    rt[0] = build();
    for (int i = 1; i <= n; i++) {
        int p = rk[i];
        rt[i] = update(p, rt[i - 1]);
    }
    cin >> q;
    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;
        cout << base[v - u + 1] + query(k, rt[u - 1], rt[v]) << endl;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i < N; i++) base[i] = base[i - 1] + (ll)i * i;
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}
