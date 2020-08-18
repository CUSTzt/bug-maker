#include<bits/stdc++.h>
#define LL long long
#define PII pair
#define MP(x, y) make_pair((x),(y))
#define fi first
#define se second
#define PB(x) push_back((x))
#define MMG(x) memset((x), -1,sizeof(x))
#define MMF(x) memset((x),0,sizeof(x))
#define MMI(x) memset((x), INF, sizeof(x))
using namespace std;
 
const int INF = 0x3f3f3f3f;
const int N = 1e5+20;
const double eps = 1e-8;
const LL mod = 1e9 + 9;
const LL trem = 383008016;
LL fac[N], le[N], ri[N];
 
LL fpow(LL a, LL n)
{
    LL res = 1;
    while(n > 0)
    {
        if(n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
 
LL Inv(LL x)
{
    return fpow(x, mod - 2);
}
 
void init()
{
    LL tinv = Inv(2);
 
    fac[0] = 1;
    le[0] = ri[0] = 1;
    LL l = ((1 + trem + mod)%mod) * tinv % mod;
    LL r = ((1 - trem + mod)%mod) * tinv % mod;
    for(LL i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mod;
    for(int i = 1; i < N; i++)
    {
        le[i] = le[i - 1] * l % mod;
        ri[i] = ri[i - 1] * r % mod;
        //cout << le[i] <<" " <<  ri[i] << endl;
    }
}
int T;
LL n, k, cc;
int main()
{
    init();
    cin >> T;
    while(T--)
    {
        scanf("%lld%lld%lld", &n, &cc,&k);
        LL ans = 0;
        cc %= (mod-1);
        n %= (mod-1);
        n = cc * n;
        //n  = ((__int128)cc*n) % (mod-1);
        for(int i = 0; i <= k; i++)
        {
            LL flag = 1;
            if((k - i) % 2)
                flag = -1;
            LL t = le[i] * ri[k - i] % mod;
            LL d = fac[k - i] * fac[i] % mod;
            LL c = fac[k] * Inv(d) % mod;
            /*--*/
            LL x = (t * (1 - fpow(t, n)) % mod) * Inv(1 - t) % mod;
            if(t == 1)
                x = n % mod;
            ans = (ans + flag * c * x ) % mod;
            ans = (ans + mod) % mod;
            //cout << t << endl;
        }
        ans = (ans * fpow(Inv(trem) % mod, k) + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}