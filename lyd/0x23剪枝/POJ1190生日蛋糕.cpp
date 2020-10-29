// #include<bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int Maxn = 10001;
int n, m, ans = 0x3f3f3f;
int Area_min[Maxn], V_min[Maxn];
void dfs(int area, int volu, int dep, int Maxr, int Maxh) {
    if (dep == 0) {
        if (volu == n) ans = min(area, ans);
        return;
    }
    if (ans - area < Area_min[dep]) return;
    if (n - volu < V_min[dep]) return;
    if ((n - volu) * 2 / Maxr > ans - area && dep < m) return;
    for (int i = Maxr, s; i >= dep; i--) {
        if (dep == m) area = i * i;
        int h = (n - V_min[dep - 1] - volu) / i / i;
        for (int j = min(h, Maxh); j >= dep; j--)
            dfs(area + 2 * i * j, volu + i * i * j, dep - 1, i - 1, j - 1);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 22; i++) {
        Area_min[i] = Area_min[i - 1] + i * i * 2;
        V_min[i] = V_min[i - 1] + i * i * i;
    }
    dfs(0, 0, m, sqrt(n), n);
    if (ans >= 0x3f3f3f)
        printf("0\n");
    else
        printf("%d\n", ans);
    return 0;
}