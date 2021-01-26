#include <bits/stdc++.h>
using namespace std;
const int p[13] = {10007, 23333, 5557, 10009, 16829, 10069, 17863, 25679, 25639, 15443, 14347, 13337, 24517};
long long c[5][25639], res[115050];
int tot;
inline long long read() {
    long long x = 0;
    char c = getchar();

    for (; c > '9' || c < '0'; c = getchar()) ;

    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - 48;

    return x;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        long long x = read();

        for (int i = 0; i < 5; ++i)
            c[i][x % p[i]] ^= x * 19260817ll + 1;
    }

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < p[i]; ++j)
            if (c[i][j] % 19260817 == 1)
                res[++tot] = c[i][j] / 19260817;

    sort(res + 1, res + tot + 1);

    for (int i = 1; i <= tot; ++i)
        if (i == 1 || res[i] != res[i - 1])
            printf("%lld ", res[i]);

    return 0;
}