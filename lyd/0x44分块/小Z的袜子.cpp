#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 50005;
struct node {
    int l, r, id;
} q[maxn];
bool cmpl(const node& a, const node& b) { return a.l < b.l; }
bool cmpr(const node& a, const node& b) { return a.r < b.r; }
int t = 200, len, n, m, ans[maxn], cnt[maxn], a[maxn];
void init() {
    t = (int)sqrt(n);
    len = (n - 1) / t + 1;
    t = (n - 1) / len + 1;
    sort(q + 1, q + 1 + m, cmpl);
    for (int i = 1, k = 1; i <= t; ++i) {
        int b = k, res = 0;
        while (k <= m && q[k].l <= i * len) ++k;
        sort(q + b, q + k, cmpr);
        memset(cnt, 0, sizeof cnt);
        for (int j = q[b].l; j <= q[b].r; ++j) res += cnt[a[j]], ++cnt[a[j]];
        ans[q[b].id] = res;
        for (int x = b + 1; x < k; ++x) {
            for (int j = q[x - 1].r + 1; j <= q[x].r; ++j)
                res += cnt[a[j]], ++cnt[a[j]];
            if (q[x - 1].l <= q[x].l)
                for (int j = q[x - 1].l; j < q[x].l; ++j)
                    res += 1 - cnt[a[j]], --cnt[a[j]];
            else
                for (int j = q[x].l; j < q[x - 1].l; ++j)
                    res += cnt[a[j]], ++cnt[a[j]];
            ans[q[x].id] = res;
        }
    }
}
ll p[maxn];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
        p[i] = (q[i].r - q[i].l); p[i] = (p[i] + 1) * p[i] / 2;
    }
    init();
    for (int i = 1; i <= m; ++i) {
        if (!ans[i])
            puts("0/1");
        else {
            ll c = __gcd(1ll * ans[i], p[i]);
            printf("%lld/%lld\n", ans[i] / c, p[i] / c);
        }
    }
    return 0;
}
