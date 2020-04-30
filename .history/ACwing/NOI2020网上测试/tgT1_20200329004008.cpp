#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;
typedef long long LL;

const int N = 100005;
const LL MOD = 1000000007;

LL ans[N], tmp[N];

void Init() {
    int t = 1000;
    for (int i = -1000; i <= 1000; i++) tmp[i + t] = i * (3 * i - 1) / 2;
    ans[0] = 1;
    for (int i = 1; i < N; i++) {
        ans[i] = 0;
        for (int j = 1; j <= i; j++) {
            if (tmp[j + t] <= i) {
                if (j & 1)
                    ans[i] += ans[i - tmp[j + t]];
                else
                    ans[i] -= ans[i - tmp[j + t]];
            } else
                break;
            ans[i] = (ans[i] % MOD + MOD) % MOD;
            if (tmp[t - j] <= i) {
                if (j & 1)
                    ans[i] += ans[i - tmp[t - j]];
                else
                    ans[i] -= ans[i - tmp[t - j]];
            } else
                break;
        }
        ans[i] = (ans[i] % MOD + MOD) % MOD;
    }
}
int main() {
    int t, n;
    Init();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}