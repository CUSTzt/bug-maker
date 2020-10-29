//#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#define ll long long
const int maxn = 1e6 + 10;
#define eps 1e-8
using namespace std;
double a[maxn], b[maxn], sum[maxn];
int main() {
    int n, L;
    scanf("%d%d", &n, &L);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    double l = -1e6, r = 1e6;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            b[i] = a[i] - mid;
        }
        for (int i = 0; i < n; i++) {
            sum[i] = sum[i - 1] + b[i];
        }
        double ans = -1e8;
        double min_init = 1e8;
        for (int i = L - 1; i < n; i++) {
            min_init = min(min_init, sum[i - L]);
            ans = max(ans, sum[i] - min_init);
        }
        if (ans >= 0) l = mid; else r = mid;
    }
    cout << int(1000 * r) << endl;
}