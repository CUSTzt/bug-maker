#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const long long mod = (1LL << 31) - 1;
int n, m;
const int N = 1005;
int d[N], a[N][N], list[N];
bool v[N];
void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[1] = 0;
    for (int i = 1; i < n; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && (!x || d[x] > d[j])) {
                x = j;
            }
        }
        v[x] = 1;
        for (int y = 1; y <= n; y++) {
            if (!v[y]) {
                d[y] = min(d[y], d[x] + a[x][y]);
            }
        }
    }
}
bool cmp(int i, int j) { return d[i] < d[j]; }
int main() {
    scanf("%d%d", &n, &m);
    memset(a, 0x3f, sizeof(a));
    for (int i = 1; i <= n; i++) {
        a[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = a[y][x] = min(a[x][y], z);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        list[i] = i;
    }
    sort(list + 1, list + n + 1, cmp);
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        int tt = 0;
        for (int j = 1; j < i; j++) {
            if (d[list[j]] + a[list[j]][list[i]] == d[list[i]]) {
                ++tt;
            }
        }
        res = (res * tt) % mod;
    }
    cout << res << endl;
}