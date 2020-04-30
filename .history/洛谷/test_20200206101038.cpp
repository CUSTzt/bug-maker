#include<bits/stdc++.h>
#define il inline
#define ll long long
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Bor(i,a,b) for(int (i)=(b);(i)>=(a);(i)--)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)>(b)?(b):(a))
using namespace std;
const int mod = 19940417 , inv = 3323403;
ll n,m;
il ll solve(ll x){
    ll ans=(x%mod*x%mod)%mod,p,c;
    for(ll i=1;i<=x;i=p+1){
        p=x/(x/i);
        ans=(ans-(p+i)*(p-i+1)/2%mod*(x/i)%mod+mod)%mod;
    }
    return ans;
}
il ll get(ll x){return x*(x+1)%mod*(x<<1|1)%mod*inv%mod;}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    ll p,sum1,sum2,sum3,ans=solve(n)*solve(m)%mod;
    if(n>m)swap(n,m);
    for(ll i=1;i<=n;i=p+1){
        p=Min(n/(n/i),m/(m/i));
        sum1=(m*n%mod*(p-i+1))%mod;
        sum2=(n/i)*(m/i)%mod*(get(p)-get(i-1)+mod)%mod;
        sum3=(p-i+1)*(p+i)/2%mod*(n/i*m%mod+m/i*n%mod);
        ans=(ans-(sum1+sum2-sum3)%mod+mod)%mod;
        printf("sum1 === %lld,  sum2 === %lld , sum3 === %lld , ans=== % lld ")
    }
    cout<<ans%mod;
    return 0;
}