//枚举a[i],b[i]然后枚举。观察数据范围
#include <bits/stdc++.h>
using namespace std;
#define abs(x) x > 0 ? x : -x
int s[1000100], sum1[1000100], sum2[1000100], a[1000100], b[1000100], n, c1, c2;
long long Ans;
inline int ra() {
    int x = 0;
    char s = getchar();
    while (!isdigit(s)) s = getchar();
    while (isdigit(s)) x = (x << 3) + (x << 1) + (s - '0'), s = getchar();
    return x;
}
int main() {
    int t, i, j, k;
    for (i = 1; i <= 1000; ++i) s[i * i] = i;
    for (i = 2; i <= 1000000; ++i) s[i] = (s[i] ? s[i] : s[i - 1]);
    t = ra();
    while (t--) {
        n = ra();
        for (i = 1; i <= n; ++i) {
            k = ra();
            sum1[k] ?: a[++c1] = k;
            sum1[k]++;
        }
        for (i = 1; i <= n; ++i) {
            k = ra();
            sum2[k] ?: b[++c2] = k;
            sum2[k]++;
        }
        for (i = 1; i <= c1; ++i) {
            for (j = 1; j <= c2; ++j) Ans += 1ll * sum1[a[i]] * sum2[b[j]] * s[abs((a[i] - b[j]))];
            sum1[a[i]] = 0;
        }
        for (i = 1; i <= c2; ++i) sum2[b[i]] = 0;
        cout << Ans << "\n";
        c1 = c2 = Ans = 0;
    }
    return 0;
}