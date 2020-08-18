#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
struct node {
    int c, d, sum;
    node(){}
    friend int operator<(node a, node b) {
        if (a.sum == b.sum)
            return a.c < b.c;
        else
            return a.sum < b.sum;
    }
    node(int _c, int _d, int _sum) { c = _c, d = _d, sum = _sum; }
    /* data */
}p[N];

int cnt;
int main() {
    int n;
    cin >> n;
    int sqr = sqrt(n + 0.5);
    for (int c = 0; c <= sqr; c++) {
        for (int d = c; d * d + c * c <= n; d++) {
            p[cnt++] = node(c, d, c * c + d * d);
        }
    }
    sort(p, p + cnt);
    for (int a = 0; a * a <= n; a++) {
        for (int b = a; b * b + a * a <= n; b++) {
            int find = n - a * a - b * b;
            int l = 0, r = cnt - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (p[mid].sum >= find)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (p[l].sum == find) {
                cout << a << " " << b << " " << p[l].c << " " << p[l].d << endl;
                return 0;
            }
        }
    }
}