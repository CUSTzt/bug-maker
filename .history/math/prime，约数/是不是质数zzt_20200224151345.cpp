//判断一个数是不是素数，如果是输出prime，如果不是输出最大的因子。
#include<stdio.h>
#include<stdlib.h>
#include<algorithm> 

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef __int128 LL;
typedef __uint128_t uLL;
template <class T> inline bool chkmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }

namespace rho {
    inline ll fpow(ll a, ll t, ll p){
        static ll r;
        for (r = 1; t; a = (LL)a * a % p, t >>= 1) if (t & 1) r = (LL)r * a % p;
        return r;
    }
    const int jp[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    inline bool judge(ll n){
        if (n == 1) return false;
        ll r, x, y; int t, i, j;
        for (i = 0; i < 12; i ++) if (n % jp[i] == 0) return n == jp[i];
        for (r = n - 1, t = 0; ~r & 1; r >>= 1, ++t);
        for (i = 0; i < 12; i ++) {
            x = fpow(jp[i], r, n);
            for (j = 0; j < t && x > 1; j ++) {
                y = (LL)x * x % n;
                if (y == 1 && x != n - 1) return false;
                x = y;
            }
            if (x != 1) return false;
        }
        return true;
    }
    ull gcd(ull a, ull b){
        #define ctz __builtin_ctzll
        int shift = ctz(a | b);
        b >>= ctz(b);
        while (a) {
            a >>= ctz(a);
            if (a < b) swap(a, b);
            a -= b;
        }
        return b << shift;
    }
    ull find(ull n){
        ull x, y = rand(), z, g; int l, k, e, i, c = rand();
        auto f = [&](ull x){ return ((uLL)x * x + c) % n; } ;
        static const int step = 1 << 9;
        for (l = 1; ; l <<= 1) {
            x = y;
            for (i = 0; i < l; i ++) y = f(y);
            for (k = 0; k < l; k += step) {
                e = min(step, l - k), g = 1, z = y;
                for (i = 0; i < e; i ++) y = f(y), g = (uLL)g * (y + n - x) % n;
                g = gcd(g, n);
                if (g == 1) continue;
                if (g == n) for (g = 1, y = z; g == 1; ) y = f(y), g = gcd(y + n - x, n);
                return g;
            }
        }
    }
    void rho(ll n, ll &a){
        static ll d;
        if (n <= a) return ;
        while (!(n & 1)) n >>= 1, a = 2;
        if (n == 1 || judge(n)) return (void)chkmax(a, n);
        for (d = find(n); d == n; d = find(n));
        if (d < n / d) d = n / d;
        rho(d, a), rho(n / d, a);
    }
}

ll test;
ll n, m;

inline ll read() {
    ll X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=(X<<3)+(X<<1)+c-'0',c=getchar();
    return X*w;
}

int main(){
    //for (srand(size_t(new char) ^ 19260817), scanf("%d", &test); test; --test) {
        //scanf("%lld", &n), m = 0, rho::judge(n) ? puts("Prime") : (rho::rho(n, m), printf("%lld\n", m));
    //}
    test = read();
    while(test--){
        read
    }
}