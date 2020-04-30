#include<bits/stdc++.h>
using namespace std;
int p[2005], c[2005];
int m;
void divide(int n) {
    m = 0;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            p[m] = i;
            c[m] = 0;
            while (n % i == 0) {
                n /= i;
                c[m]++;
            }
            m++;
        }
    }
    if (n > 1) {
        p[m] = n, c[m] = 1;
        m++;
    }
}
int get(long long n, int p)  // 求n！中p1的次数
{
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}
int main() {
    int t;

    scanf("%d", &t);
    while (t--) {
        int n;
        int pp;
        long long ans = 0;
        long long nn;
        int k;
        n = 0;
        k = 0;
        scanf("%d", &pp);
        if (pp == 1) {
            cout << 1 << endl;
            continue;
        }
        divide(pp);
        for (int i = 0; i < m; i++) {
            nn = p[i];
            while (get(nn, p[i]) < c[i]) {
                nn = nn + p[i];
            }
            ans = max(ans, nn);
        }
        cout << ans << endl;
    }
    return 0;
}