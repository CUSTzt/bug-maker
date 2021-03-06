// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define s (1 << 18)

const int N = 1e6 + 100;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct segtree {
    ll seg[s * 2];
    ll lazy[s * 2];
    void lazy_evaluate(int k) {
        if (k * 2 + 2 >= s * 2) return;
        lazy[k * 2 + 2] += lazy[k];
        lazy[k * 2 + 1] += lazy[k];
        seg[k * 2 + 2] += lazy[k];
        seg[k * 2 + 1] += lazy[k];
        lazy[k] = 0;
    }
    ll update(int beg, int end, int idx, int lb, int ub, ll num) {
        if (ub < beg || end < lb) {
            return seg[idx];
        }
        if (beg <= lb && ub <= end) {
            lazy[idx] += num;
            seg[idx] += num;
            return seg[idx];
        }
        if (lazy[idx]) {
            lazy_evaluate(idx);
        }
        return seg[idx] = max(
                   update(beg, end, idx * 2 + 1, lb, (lb + ub) / 2, num),
                   update(beg, end, idx * 2 + 2, (lb + ub) / 2 + 1, ub, num));
    }
    ll query(int beg, int end, int idx, int lb, int ub) {
        if (ub < beg || end < lb) {
            return -INF;
        }
        if (beg <= lb && ub <= end) {
            return seg[idx];
        }
        if (lazy[idx]) {
            lazy_evaluate(idx);
        }
        return max(query(beg, end, idx * 2 + 1, lb, (lb + ub) / 2),
                   query(beg, end, idx * 2 + 2, (lb + ub) / 2 + 1, ub));
    }
} tree;
int n, m;
vector<pair<int, pair<int, int> > > zz[N];
void solve() {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < zz[i].size(); j++) {
            int zcj = zz[i][j].ff;
            int zb = zz[i][j].ss.ff;
            int ZB = zz[i][j].ss.ss;
            if (zcj == 1) {
                tree.update(0, i - 1, 0, 0, s - 1, 1ll * ZB);
            } else {
                tree.update(0, zb - 1, 0, 0, s - 1, -1ll * ZB);
            }
        }
        ll tmp = tree.query(0, i - 1, 0, 0, s - 1);
        tree.update(i, i, 0, 0, s - 1, tmp);
        ans = max(ans, tmp);
        // cout << "ans == " << ans << endl;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        zz[l].pb({1, {r, x}});
        zz[r + 1].pb({-1, {l, x}});
    }
    solve();
    return 0;
}
