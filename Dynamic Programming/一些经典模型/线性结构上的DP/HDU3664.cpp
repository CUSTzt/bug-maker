//others
#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define MP make_pair
#define PB push_back
#define SD second
#define FT first 
typedef long long ll;
using namespace std;
int T,n;
const ll INF=0x3f3f3f3f3f3f3f3f;
tr1::unordered_map<ll,ll>S;
inline ll power(ll a,ll b,ll mod){
    int rs=1;a=a%mod;
    for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)rs=1ll*rs*a%mod;
    return rs;  
}
inline ll gcd(ll x,ll y){return y?(gcd(y,x%y)):x;}
typedef pair<int,int> pii;
namespace SP1{
    vector<pii>fac;
    ll nowlen,M;
    inline void mul(ll *a,ll *b,ll mod){
        unsigned long long bd=a[0]*b[0],bc=a[0]*b[1],ad=a[1]*b[0],ac=a[1]*b[1];
        a[1]=(bc+ad+ac)%mod,a[0]=(bd+ac)%mod;
    }
    inline void power_p(ll *a,ll b,ll mod){
        ll c[2]={1,0};
        for(;b;b>>=1,mul(a,a,mod))
            if(b&1)mul(c,a,mod);
        a[0]=c[0];a[1]=c[1];
    }
    inline bool check(ll sum){
        ll b[2]={0,1};
        power_p(b,sum,M);
        return b[1]==0&&b[0]==1;
    } 
    inline void dfs(int pos,ll sum){
        if(pos==fac.size()){
            (sum!=1&&check(sum))?(nowlen=min(nowlen,sum)):0;
            return;
        }
        ll rs=1;
        for(int i=0;i<=fac[pos].SD;++i){
            dfs(pos+1,sum*rs);
            rs*=fac[pos].FT;
        }
    }
    inline ll getlen(ll x){
        if(x==2)return 3;
        if(x==3)return 8;
        if(x==5)return 20;
        if(S.find(x)!=S.end())return S[x];
        ll base=(power(5,(x-1)/2,x)==1)?(x-1):(2*x+2);
        fac.clear();nowlen=INF;M=x;
        for(int i=2;i*i<=base;++i){
            if(!(base%i)){
                pii t=MP(i,0);
                while(!(base%i))base/=i,++t.SD;
                fac.PB(t);
            }
        }
        if(base!=1)fac.PB(MP(base,1));
        dfs(0,1);return S[x]=nowlen;
    }
}
vector<pii>fac;
ll ans;
inline void solve(int n){
    if(n==1){puts("1");return;}
    fac.clear();
    for(int i=2;i*i<=n;i++){
        if(!(n%i)){
            pii t=MP(i,0);
            while(!(n%i))n/=i,++t.SD;
            fac.PB(t);
        }
    }
    if(n!=1)fac.PB(MP(n,1)); 
    ans=1;
    for(int i=0;i<fac.size();++i){
        ll l=SP1::getlen(fac[i].FT);
        l=l*power(fac[i].first,fac[i].second-1,INF);
        ans=(ans*l)/gcd(ans,l);
    }
    printf("%llu\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        solve(n);
    }
}