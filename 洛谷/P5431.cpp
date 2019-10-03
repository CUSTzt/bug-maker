#include <bits/stdc++.h>

#define int long long 
#define ll long long 
using namespace std;
const int maxn = 5e6+500;
int pre[maxn] ,n ,p , k, tot, a[maxn], inv[maxn]; 
int suf[maxn] ;
template <typename T>
inline void read(T &x)//快读
{
    char c;
    x = 0;
    int fu = 1;
    c = getchar();
    while(c > 57 || c < 48)
    {
        if(c == 45)
        {
            fu = -1;
        }
        c = getchar();
    }
    while(c <= 57 && c >= 48)
    {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x)//快输
{
    if(x < 0)
    {
        putchar(45);
        x = -x;
    }
    if(x > 9)
    {
        fprint(x / 10);
    }
    putchar(x % 10 + 48);
}
ll mul(ll a,ll b,ll mod) {
    ll ret=0;
    while(b) {
        if(b&1)
            ret=(ret+a)%mod;
        a=(a<<1)%mod;
        b=b>>1;
    }
    return ret;
}
ll quickPow(ll a,ll b,ll mod) {
    ll ret=1;
    while(b) {
        if(b&1)
            ret=mul(ret,a,mod);  //直接相乘的话可能会溢出
        a=mul(a,a,mod);
        b=b>>1;
    }
    return ret;
}
int ans = 0;
 main()
{
   // scanf("%lld %lld %lld", &n , &p , &k);
    read(n);
    read(p);
    read(k);
    pre[0] = 1;
    // inv_init(n , p);
    for(int i = 1; i <= n;i++){
        //scanf("%lld", &a[i]);
        read(a[i]);
        pre[i] = (pre[i-1] * a[i]) % p;
    }
    suf[n + 1] = quickPow(pre[n] , p-2,p);
    for(int i = n ;i ;i--)
        suf[i] = (suf[i+1] * a[i]) % p;
    int tmp = k;
    for(int i = 1; i <= n;i++){
        ans = (ans + (suf[i+1]*pre[i-1]%p)*tmp)%p;
        tmp = (tmp*k)%p;
    }
    printf("%lld", ans);
}
