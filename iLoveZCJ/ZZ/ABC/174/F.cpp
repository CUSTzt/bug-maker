// 一行有颜色的小球，q次询问，求【L,R】之间包含球的颜色的数量。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 100;
namespace bit {
ll c[N];
inline int lowbit(int x) { return x & -x; }
void add(int x, ll v) {
    for (int i = x; i < N; i += lowbit(i)) c[i] += v;
}
ll sum(int x) {
    ll ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) ret += c[i];
    return ret;
}
int kth(ll k) {
    int p = 0;
    for (int lim = 1 << 20; lim; lim /= 2) {
        if (p + lim < N && c[p + lim] < k) {
            p += lim;
            k -= c[p];
        }
    }
    return p + 1;
}
ll sum(int l, int r) { return sum(r) - sum(l - 1); }
void add(int l, int r, ll v) { add(l, v), add(r + 1, -v); }
}  // namespace bit
struct node {
    int l, r, pos;
    friend int operator<(const node& a, const node& b) { return a.r < b.r; }
} q[N];
using namespace bit;
int vis[N], cc[N], ans[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, qq;
    cin >> n >> qq;
    for (int i = 1; i <= n; i++) {
        cin >> cc[i];
    }
    for (int i = 1; i <= qq; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].pos = i;
    }
    sort(q + 1, q + 1 + qq);
    int st = 1;
    for (int i = 1; i <= qq; i++) {
        for (int j = st; j <= q[i].r; j++) {
            if (vis[cc[j]]) add(vis[cc[j]], -1);  // 删除之前只保留一个颜色
            add(j, 1), vis[cc[j]] = j;            // 标记该颜色现在位置
        }
        st = q[i].r + 1;
        ans[q[i].pos] = sum(q[i].l, q[i].r);
    }
    for(int i = 1; i <= qq; i++)cout << ans[i] << endl;
    return 0;
}