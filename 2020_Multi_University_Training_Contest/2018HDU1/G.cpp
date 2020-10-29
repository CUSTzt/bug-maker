#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll inv2 = 500000004;
ll pw[80];   // pw[i]=2^i
ll cnt[80];  // cnt[i]=2^(i+1)-1
ll n, pos;
void init() {  //预处理
    pw[0] = cnt[0] = 1;
    for (int i = 1; i <= 62; ++i) {
        pw[i] = pw[i - 1] * 2;
        cnt[i] = 2 * pw[i] - 1;
    }
}
ll getsum(ll p) {  //计算序列中出现的所有1,2...p的和
    ll ans = 0;
    for (ll i = 1; i <= p; i *= 2) {
        ll num = (p - i) / (2 * i);   //首项=i, num=项数-1
        ll last = i + num * (2 * i);  //公差是2*i, 算出末项
        num = (num + 1) % mod;  //开始写成++num然后就WA了,简直要命
        ll tmp = (i + last) % mod;  //等差数列求和S=(首项+末项)*项数/2
        tmp = tmp * num % mod;
        tmp = tmp * inv2 % mod;
        tmp = tmp * (__builtin_ffsll(i)) % mod;  //乘以对应的出现次数
        // tmp=tmp*(__builtin_ctzll(i)+1)%mod;//等价写法
        ans = (ans + tmp) % mod;
    }
    return (1 + ans) % mod;  //加上第一项被忽略的1
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        --n;
        if (0 == n) {
            puts("1");
            continue;
        }
        pos = 0;
        ll tmp = n;
        for (int i = 62; i >= 0; --i) {  // 63的时候cnt会爆
            if (tmp >= cnt[i]) {
                tmp -= cnt[i];
                pos += pw[i];
            }
        }
        ll ans = getsum(pos);
        if (tmp)
            ans = (ans + tmp % mod * (pos + 1) % mod) % mod;  //如果有剩下的几项，就再加上
        printf("%lld\n", ans);
    }
    return 0;
}