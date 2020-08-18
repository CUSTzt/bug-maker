#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long long ll;
const int maxn = 1e5 + 16;
LL x, y, a[maxn];
struct BigIntegerFactor {
    const static int maxm = 1e6 + 16;
    LL prime[maxm], p[maxm], fac[maxm], sz, cnt;  //多组输入注意初始化cnt = 0
    inline ll mul(ll a, ll b, ll p) {
        if (p <= 1000000000)
            return a * b % p;
        else if (p <= 1000000000000ll)
            return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)))) % p;
        else {
            ll d = (ll)floor(a * (long double)b / p + 0.5);
            ll ret = (a * b - d * p) % p;
            if (ret < 0) ret += p;
            return ret;
        }
    }
    void init(int maxn) {
        int tot = 0;
        sz = maxn - 1;
        for (int i = 1; i <= sz; ++i) p[i] = i;
        for (int i = 2; i <= sz; ++i) {
            if (p[i] == i) prime[tot++] = i;
            for (int j = 0; j < tot && 1ll * i * prime[j] <= sz; ++j) {
                p[i * prime[j]] = prime[j];
                if (i % prime[j] == 0) break;
            }
        }
    }
    LL powl(LL a, LL x, LL mod) {
        LL res = 1LL;
        while (x) {
            if (x & 1) res = mul(res, a, mod);
            a = mul(a, a, mod);
            x >>= 1;
        }
        return res;
    }
    bool check(LL a, LL n) {  //二次探测原理检验n
        LL t = 0, u = n - 1;
        while (!(u & 1)) t++, u >>= 1;
        LL x = powl(a, u, n), xx = 0;
        while (t--) {
            xx = mul(x, x, n);
            if (xx == 1 && x != 1 && x != n - 1) return false;
            x = xx;
        }
        return xx == 1;
    }
    bool miller(LL n, int k) {
        if (n == 2) return true;
        if (n < 2 || !(n & 1)) return false;
        if (n <= sz) return p[n] == n;
        for (int i = 0; i <= k; ++i) {  //测试k次
            if (!check(rand() % (n - 1) + 1, n)) return false;
        }
        return true;
    }
    inline LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }
    inline LL Abs(LL x) { return x < 0 ? -x : x; }
    LL Pollard_rho(LL n) {  //基于路径倍增的Pollard_Rho算法
        LL s = 0, t = 0, c = rand() % (n - 1) + 1, v = 1, ed = 1;
        while (1) {
            for (int i = 1; i <= ed; ++i) {
                t = (mul(t, t, n) + c) % n;
                v = mul(v, Abs(t - s), n);
                if (i % 127 == 0) {
                    LL d = gcd(v, n);
                    if (d > 1) return d;
                }
            }
            LL d = gcd(v, n);
            if (d > 1) return d;
            s = t;
            v = 1;
            ed <<= 1;
        }
    }
    void getfactor(LL n) {  //得到所有的质因子(可能有重复的)
        if (n <= sz) {
            while (n != 1) fac[cnt++] = p[n], n /= p[n];
            return;
        }
        if (miller(n, 6))
            fac[cnt++] = n;
        else {
            LL d = n;
            while (d >= n) d = Pollard_rho(n);
            getfactor(d);
            getfactor(n / d);
        }
    }
    LL cal(LL n, LL x) {  //计算 n! 中质因子 x 的数量
        LL num = 0;
        while (n) {
            num += n / x;
            n = n / x;
        }
        return num;
    }
    LL solve(int n, LL x, LL y) {
        map<LL, LL> mp;
        LL ans = 4e18;
        cnt = 0;
        getfactor(x);
        for (int i = 0; i < cnt; ++i) mp[fac[i]]++;
        map<LL, LL>::iterator it = mp.begin();
        while (it != mp.end()) {
            LL num = 0;
            for (int i = 1; i <= n; ++i) {
                num += cal(a[i], it->first);
            }
            ans = min(ans, (cal(y, it->first) - num) / it->second);
            it++;
        }
        return ans;
    }
} Q;
int main() {
    Q.init(100000);
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld %lld", &n, &x, &y);
        for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
        printf("%lld\n", Q.solve(n, x, y));
    }
    return 0;
}