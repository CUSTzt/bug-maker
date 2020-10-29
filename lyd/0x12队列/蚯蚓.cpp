#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 7e6 + 20;
int n, m, u, v, t, q;
int q1[N], q2[M], q3[M];
int hh1, hh2, hh3, tt1, tt2 = -1, tt3 = -1, delta;
bool cmp(int a, int b) { return a > b; }
int get_max() {
    int x = INT_MIN;
    if (hh1 <= tt1) x = max(x, q1[hh1]);
    if (hh2 <= tt2) x = max(x, q2[hh2]);
    if (hh3 <= tt3) x = max(x, q3[hh3]);
    if (hh1 <= tt1 && x == q1[hh1])
        hh1++;
    else if (hh2 <= tt2 && x == q2[hh2])
        hh2++;
    else if (hh3 <= tt3 && x == q3[hh3])
        hh3++;
    return x;
}
int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
    for (int i = 0; i < n; i++) scanf("%d", &q1[i]);
    sort(q1, q1 + n, cmp);
    tt1 = n - 1;
    for (int i = 1; i <= m; i++) {
        int x = get_max();
        x += delta;
        int left = x * 1ll * u / v, right = x - left;
        if (i % t == 0) printf("%d ", x);
        delta += q;
        left -= delta, right -= delta;
        q2[++tt2] = left;
        q3[++tt3] = right;
    }
    puts("");
    for (int i = 1; i <= n + m; i++) {
        int x = get_max();
        if (i % t == 0) printf("%d ", x + delta);
    }
    return 0;
}