#pragma GCC optimize(2)
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 100 + 5;
#define LL long long
LL Multiply(LL a, LL b, LL c) {  //计算a*b%c
    LL sum = 0, temp = a;
    while (b) {
        if (b & 1) sum += temp;
        if (sum >= c) sum -= c;
        temp <<= 1;
        if (temp >= c) temp -= c;
        b >>= 1;
    }
    return sum;
}
LL PowMod(LL a, LL b, LL c) {  //计算a^b%c
    LL sum = 1;
    while (b) {
        if (b & 1) sum = Multiply(sum, a, c);
        a = Multiply(a, a, c);
        b >>= 1;
    }
    return sum;
}
bool Check(LL a, LL n, LL x,
           LL t) {  //通过a^(n-1)%n==1(mod n)来判断n是不是素数,合数返回true
    long long ans = PowMod(a, x, n);
    long long last = ans;
    for (int i = 1; i <= t; i++) {
        ans = Multiply(ans, ans, n);
        if (ans == 1 && last != 1 && last != (n - 1)) return true;  //合数
        last = ans;
    }
    if (ans != 1)
        return true;
    else
        return false;
}
bool MillerRabin(LL n) {  //判断n是不是素数，是返回YES ,,可能是伪素数
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;
    long long x = n - 1, t = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        t++;
    }

    srand(time(NULL));
    for (int i = 0; i < 8; i++) {
        LL a = rand() % (n - 1) + 1;
        if (Check(a, n, x, t)) return false;
    }
    return true;
}
LL factor[200];  //质因数分解结果
int tol;         //质因数个数  0--tol-1
LL Gcd(LL a, LL b) {
    long long t;
    while (b) {
        t = a;
        a = b;
        b = t % b;
    }
    if (a >= 0)
        return a;
    else
        return -a;
}
LL PollardRho(LL x, LL c) {  //找出x的一个因子
    LL i = 1, k = 2;
    srand(time(NULL));
    LL x0 = rand() % (x - 1) + 1;
    LL y = x0;  // floyd判环
    while (1) {
        i++;
        x0 = ((Multiply(x0, x0, x)) + c) % x;
        LL d = Gcd(y - x0, x);
        if (d != 1 && d != x) return d;
        if (y == x0) return x;
        if (i == k) {
            y = x0;
            k <<= 1;
        }
    }
}
void findfac(LL n, int k) {  //找到所有的因子,    k是一个随机数
    if (n < 2) return;
    if (MillerRabin(n)) {
        factor[tol++] = n;
        return;
    }
    LL p = n;
    int c = k;
    while (p >= n) p = PollardRho(p, c--);  //随机值变化，防止死循环
    findfac(p, k);
    findfac(n / p, k);
}
int a[N];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                a[i] = 0;
                continue;
            }
            bool flag = 0;
            while (a[i] % 2 == 0) a[i] /= 2, flag = 1;
            if (a[i] == 1) {
                continue;
            }
            tol = 0;
            findfac(a[i], 107);
            a[i] = tol + flag;
        }
        /*
        puts("a--");
        for(int i=1;i<=n;i++)
                printf("%d ",a[i]);
        puts("\n");
        */
        int ans = 0;
        for (int i = 1; i <= n; i++) ans ^= a[i];
        if (ans)
            puts("W");
        else
            puts("L");
    }
    return 0;
}