#include <cstdio>
#include <iostream>
#define N 100007
using namespace std;
int T, n, m, a[N], b[N], p[N], q[N];
long long sa[N], sb[N];
bool check1(int x, int y, int z) {
    return (sa[z] - sa[y]) * (y - x) >= (sa[y] - sa[x]) * (z - y);
}
bool check2(int x, int y, int z) {
    return (sb[z] - sb[y]) * (y - x) >= (sb[y] - sb[x]) * (z - y);
}
bool check3(int x, int y, int z, int w) {
    return (sa[y] - sa[x]) * (w - z) >= (sb[w] - sb[z]) * (y - x);
}
int main() {
    // std
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case " << cas << ": ";
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), sa[i] = sa[i - 1] + a[i];
        for (int i = 1; i <= m; ++i)
            scanf("%d", &b[i]), sb[i] = sb[i - 1] + b[i];
        p[0] = q[0] = 0;
        for (int i = 0; i <= n; p[++p[0]] = i++)
            while (p[0] >= 2 && check1(p[p[0] - 1], p[p[0]], i)) --p[0];
        for (int i = 0; i <= m; q[++q[0]] = i++)
            while (q[0] >= 2 && check2(q[q[0] - 1], q[q[0]], i)) --q[0];
        long long ans = 0;
        for (int i = 1, j = 1, k = 1; i < p[0] || j < q[0];)
            if (j == q[0] ||
                (i < p[0] && check3(p[i], p[i + 1], q[j], q[j + 1])))
                for (int t = p[i++] + 1; t <= p[i]; ++t, ++k)
                    ans += 1LL * a[t] * k;
            else
                for (int t = q[j++] + 1; t <= q[j]; ++t, ++k)
                    ans += 1LL * b[t] * k;
        cout << ans << endl;
    }
}