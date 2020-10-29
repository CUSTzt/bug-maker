#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int tr[2][maxn];
void add(int x, int v, int p) {
    while (x < maxn) {
        tr[p][x] += v;
        x += x & -x;
    }
}
int query(int x, int p) {
    int ret = 0;
    while (x) {
        ret += tr[p][x];
        x -= x & -x;
    }
    return ret;
}
int a[maxn];
int main() {
    int n;
    scanf("%d", &n);
    long long ans = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        add(a[i], 1, 0);
    }
    for (int i = n; i >= 1; i--) {
        add(a[i], -1, 0);
        int t1 = query(a[i], 0), t2 = query(a[i], 1);
        ans += 1LL * t1 * t2;
        ans2 += 1LL * (i - 1 - t1) * (n - i - t2);
        add(a[i], 1, 1);
    }
    cout << ans2 << " " << ans << endl;
}