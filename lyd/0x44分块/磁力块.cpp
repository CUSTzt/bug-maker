#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6;
const int w = 500;
struct node {
    ll d, r;
    ll m, p;
} a[N];
ll D[N], x0, y_0, now, L[N], R[N], v[N], n, tot, l, r, p, x, y;
queue<ll> q;
bool cmp_d(node a, node b) { return a.d < b.d; }
bool cmp_m(node a, node b) { return a.m < b.m; }
int main() {
    cin >> x0 >> y_0 >> a[0].p >> a[0].r >> n;
    a[0].r *= a[0].r;  //第一块磁铁
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> a[i].m >> a[i].p >> a[i].r;
        a[i].r *= a[i].r;
        a[i].d = (x0 - x) * (x0 - x) + (y_0 - y) * (y_0 - y);  //计算距离
    }
    sort(a + 1, a + 1 + n, cmp_d);
    for (ll i = 1; i <= n; i += w) {
        L[++tot] = i; R[tot] = min(n, i + w - 1);  //计算L和R的范围,也就是第i大块的范围
        D[tot] = a[R[tot]].d; sort(a + L[tot], a + R[tot] + 1, cmp_m);  //大块内则排序
    }
    q.push(0);
    ll ans = 1;
    while (q.size()) {
        ll l = q.front();
        now = a[l].r; p = a[l].p; q.pop();
        for (ll i = 1; i <= tot; i++) {
            if (D[i] > now) {
                for (ll j = L[i]; j <= R[i]; j++)
                    if (!v[j] && a[j].d <= now && a[j].m <= p)  //没有吸过来,而且在范围内
                    {
                        q.push(j); ans++; v[j] = 1;
                    }
                break;
            }
            while (L[i] <= R[i] &&a[L[i]].m <= p)  //加入一块磁铁石,然后把则块磁铁石可以吸收的磁铁石放进去
            {
                if (!v[L[i]]){
                    q.push(L[i]); ans++;
                }
                ++L[i];
            }
        }
    }
    cout << ans - 1;  //不算刚开始的赠送磁石
}
