#include<bits/stdc++.h>
typedef long long LL;
const LL mod=998244353,g=3,maxn=1e6+9;
inline LL Pow(LL base,LL b){
    LL ret(1);
    while(b){
        if(b&1) ret=ret*base%mod; base=base*base%mod; b>>=1;
    }return ret;
}
LL r[maxn];
inline LL Fir(LL n){
    LL limit(1),len(0);
    while(limit<(n<<1)){
        limit<<=1; ++len;
    }
    for(LL i=0;i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)<<len-1);
    return limit;
}
inline void NTT(LL *a,LL n,LL type){
    for(LL i=0;i<n;++i) if(i<r[i]) std::swap(a[i],a[r[i]]);
    for(LL mid=1;mid<n;mid<<=1){
        LL wn(Pow(g,(mod-1)/(mid<<1))); if(type==-1) wn=Pow(wn,mod-2);
        for(LL R=mid<<1,j=0;j<n;j+=R)
            for(LL k=0,w=1;k<mid;++k,w=w*wn%mod){
            	LL x(a[j+k]),y(w*a[j+mid+k]%mod);
            	a[j+k]=(x+y)%mod; a[j+mid+k]=(x-y+mod)%mod;
            }
    }
    if(type==-1){
        LL ty(Pow(n,mod-2)); for(LL i=0;i<n;++i) a[i]=a[i]*ty%mod;
    }
}
LL T[maxn],F[maxn],H[maxn],G[maxn],fac[maxn],fav[maxn],tmp[maxn],sum[maxn],B[maxn];
inline void Mul(LL n,LL *a,LL *b,LL *ans){
    LL limit(Fir(n));
    NTT(a,limit,1); NTT(b,limit,1);
    for(LL i=0;i<limit;++i) ans[i]=a[i]*b[i]%mod;
    NTT(ans,limit,-1);
}
inline void Solve(LL n,LL *a){
    if(!n){ a[0]=1; return; }
    if(n==1){ a[1]=1; return; }
    LL len(n/2);
    Solve(len,a);
    
    LL limit(Fir(len+1));
    for(LL i=0;i<=len;++i) F[i]=Pow(len,i)*fav[i]%mod;
    for(LL i=0;i<=len;++i) H[i]=fac[i]*a[i]%mod;
    for(LL i=0;i<=(len>>1);++i) std::swap(H[i],H[len-i]);
    for(LL i=len+1;i<limit;++i) F[i]=H[i]=0;
    NTT(F,limit,1); NTT(H,limit,1);
    for(LL i=0;i<limit;++i) G[i]=F[i]*H[i]%mod;
    NTT(G,limit,-1);
    for(LL i=0;i<=len;++i) tmp[i]=G[len-i]*Pow(fac[i],mod-2)%mod;//right
    
    Mul(len+1,a,tmp,B);//left * right
    for(LL i=0;i<=(len<<1);++i) a[i]=B[i];
    for(LL i=(len<<1)+1;i<=(len<<2);++i) a[i]=tmp[i]=0;
    
    if(n&1){
        for(LL i=0;i<n;++i) T[i]=a[i];
        for(LL i=1;i<=n;++i) a[i]=(T[i-1]+(n-1)*T[i]%mod)%mod;
    }
}
inline LL Get_c(LL n,LL m){
    return fac[n]*fav[m]%mod*fav[n-m]%mod;
}
LL n;
LL ans[maxn];
int main(){
    scanf("%lld",&n);
    fac[0]=fac[1]=1;
    for(LL i=2;i<=n;++i) fac[i]=fac[i-1]*i%mod;
    fav[n]=Pow(fac[n],mod-2);
    for(LL i=n;i>=1;--i) fav[i-1]=fav[i]*i%mod;
    Solve(n,ans);
	for(LL i=0;i<=n;++i) printf("%lld ",ans[i]);printf("\n");
	return 0;
}