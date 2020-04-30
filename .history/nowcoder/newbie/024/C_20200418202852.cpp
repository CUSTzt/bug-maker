#include<bits/stdc++.h>

using namespace std;
const int  N = 3000;
int n, m, j, x1, y1, x2, y2, p;
char op[9];
struct BIT {
    int a[N][N];
    void add(int x, int y, int p) {
        for (; x <= n; x += x &−x)
            for (j = y; j <= m; j += j &−j) a[x][j] += p;
    }
    int sum(int x, int y) {
        int t = 0;
        for (; x; x−= x &−x)
            for (j = y; j; j−= j &−j) t += a[x][j];
        return t;
    }
} T1, T2, T3, T4;
void up(int x, int y, int p) {
    if (!x || !y) return;
    T1.add(x, y, x * y * p);
    T2.add(x, 1, x * p), T2.add(x, y,−x * p);
    T3.add(1, y, y * p), T3.add(x, y,−y * p);
    T4.add(1, 1, p), T4.add(x, y, p);
    T4.add(x, 1,−p), T4.add(1, y,−p);
}
int ask(int x, int y) {
    return x && y ? T1.sum(x, y) + T2.sum(x, y) * y + T3.sum(x, y) * x +
                        T4.sum(x, y) * x * y
                  : 0;
}
