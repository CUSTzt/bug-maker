#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int t;
// https://blog.csdn.net/qq_43316231/article/details/99751317
int f(ll a,ll b,ll c,ll n){
    ///因为防止爆long long 所以mod2，&1比mod2快很多
    if(!a)return (((n+1)&1)*(b/c))&1;
    if(a>=c||b>=c){
        ll res=((n%4)==0||(n+1)%4==0)?0:1;
        return ((f(a%c,b%c,c,n)&1)+(((a/c)*res)&1)+(((n+1)&1)*(b/c)&1))&1;
    }
    else{
        ll m=(a*n+b)/c;
        return (((m*n)&1)^f(c,c-b-1,a,m-1))&1;
        ///减法可以变异或因为减法也是奇偶相同为偶，不同为奇
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans=0,sqrtn=min(30000000ll,n);
        for(ll i=1;i<=sqrtn;i++)ans^=n%i;
        for(ll i=sqrtn+1,j;i<=n;i=j+1){
            j=n/(n/i);
            ll lim=n/i*(j-i)+n%j,res=0;
            for(ll k=1; k<=lim; k<<=1)
                res+=f(n/i,n%j,k,j-i)*k;
            ans^=res;
        }
        printf("%lld\n",ans);
    }
    return 0;
}