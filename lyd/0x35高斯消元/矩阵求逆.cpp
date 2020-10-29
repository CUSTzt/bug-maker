#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 405;
const LL mod = 1e9 + 7;
int n, m;
LL f[N][N << 1];
LL r, ret;
LL ksm(LL u, LL v) {  //求逆元
    ret = 1;
    while (v) {
        if (v & 1) ret = ret * u % mod;
        u = u * u % mod;
        v >>= 1;
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    m = n * 2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; j++) scanf("%lld", &f[i][j]);
        f[i][n + i] = 1;  //单位矩阵
    }
    for (int i = 1; i <= n; ++i) {  //高斯消元板子
        for (int j = i; j <= n; j++)
            if (f[j][i]) {
                for (int k = 1; k <= m; k++) swap(f[i][k], f[j][k]);  //先交换
                break;
            }
        if (!f[i][i]) {
            puts("No Solution");
            return 0;
        }                             //判断是否有解
        r = ksm(f[i][i], mod - 2);    //求逆元
        for (int j = i; j <= m; ++j)  //更改当前行
            f[i][j] = f[i][j] * r % mod;
        for (int j = 1; j <= n; ++j)  //更改其他行信息
            if (j != i) {
                r = f[j][i];
                for (int k = i; k <= m; ++k)
                    f[j][k] = (f[j][k] - r * f[i][k] % mod + mod) % mod;
            }
    }
    for (int i = 1; i <= n; ++i, puts(""))
        for (int j = n + 1; j <= m; ++j) printf("%lld ", f[i][j]);
}