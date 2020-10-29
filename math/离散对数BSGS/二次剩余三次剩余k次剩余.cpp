#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
template<class T>
inline T dw();
template<>
inline ll dw<ll>() {return 1;}
template<>
inline int dw<int>() {return 1;}
typedef pair<ll,ll> pll;
ll pll_s;
inline pll mul(pll a,pll b,ll p)
{
    pll ans;
    ans.fi=a.fi*b.fi%p+a.se*b.se%p*pll_s%p;
    ans.se=a.fi*b.se%p+a.se*b.fi%p;
    ans.fi%=p; ans.se%=p;
    return ans;
}
inline ll mul(ll a,ll b,ll c)
{return a*b%c;}
//a^b mod c
template<class T>
T qp(T a,ll b,ll c)
{
    T ans=dw<T>();
    while(b)
    {
        if(b&1) ans=mul(ans,a,c);
        a=mul(a,a,c); b>>=1;
    }
    return ans;
}
inline ll ll_rnd()
{
    ll ans=0;
    for(int i=1;i<=5;i++)
        ans=ans*32768+rand();
    if(ans<0) ans=-ans;
    return ans;
}
//(x,y) -> x+sqrt(pll_s)*y
template<>
inline pll dw<pll>() {return pll(1,0);}
//find (possibly) one root of x^2 mod p=a
//correctness need to be checked
ll sqr(ll a,ll p)
{
    if(!a) return 0;
    if(p==2) return 1;
    ll w,q;
    while(1)
    {
        w=ll_rnd()%p;
        q=w*w-a;
        q=(q%p+p)%p;
        if(qp(q,(p-1)/2,p)!=1)
            break;
    }
    pll_s=q;
    pll rst=qp(pll(w,1),(p+1)/2,p);
    ll ans=rst.fi; ans=(ans%p+p)%p;
    return ans;
}
//solve x^2 mod p=a
vector<ll> all_sqr(ll a,ll p)
{
    vector<ll> vec;
    a=(a%p+p)%p;
    if(!a) {vec.pb(0); return vec;}
    ll g=sqr(a,p);
    ll g2=(p-g)%p;
    if(g>g2) swap(g,g2);
    if(g*g%p==a) vec.pb(g);
    if(g2*g2%p==a&&g!=g2) vec.pb(g2);
    return vec;
}
ll s3_a;
//f0+f1*x+f2*x^2 (for x^3=s3_a)
struct s3
{
    ll s[3];
    s3() {s[0]=s[1]=s[2]=0;}
    s3(ll* p) {s[0]=p[0]; s[1]=p[1]; s[2]=p[2];}
    s3(ll a,ll b,ll c) {s[0]=a; s[1]=b; s[2]=c;}
};
template<>
s3 dw<s3>() {return s3(1,0,0);}
s3 rs3(ll p)
{
    return s3(ll_rnd()%p,ll_rnd()%p,ll_rnd()%p);
}
s3 mul(s3 a,s3 b,ll p)
{
    ll k[3]={};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i+j<3) k[i+j]+=a.s[i]*b.s[j]%p;
            else k[i+j-3]+=a.s[i]*b.s[j]%p*s3_a%p;
        }
    }
    for(int i=0;i<3;i++) k[i]%=p;
    return s3(k[0],k[1],k[2]);
}
//solve x^3 mod p=a
vector<ll> all_cr(ll a,ll p)
{
    vector<ll> vec;
    a=(a%p+p)%p;
    if(!a) {vec.pb(0); return vec;}
    if(p<=3)
    {
        for(int i=0;i<p;i++)
        {
            if(i*i*i%p==a) vec.pb(i);
        }
        return vec;
    }
    if(p%3==2)
    {
        vec.pb(qp(a,(p*2-1)/3,p));
        return vec;
    }
    if(qp(a,(p-1)/3,p)!=1) return vec;
    ll l=(sqr(p-3,p)-1)*qp(2LL,p-2,p)%p,x;
    s3_a=a;
    while(1)
    {
        s3 u=rs3(p);
        s3 v=qp(u,(p-1)/3,p);
        if(v.s[1]&&!v.s[0]&&!v.s[2])
        {x=qp(v.s[1],p-2,p); break;}
    }
    x=(x%p+p)%p;
    vec.pb(x); vec.pb(x*l%p); vec.pb(x*l%p*l%p);
    sort(vec.begin(),vec.end());
    return vec;
}
map<ll,ll> gg;
ll yss[2333]; int yyn=0;
//find x's primitive root
inline ll org_root(ll x)
{
    ll& pos=gg[x];
    if(pos) return pos;
    yyn=0; ll xp=x-1;
    for(ll i=2;i*i<=xp;i++)
    {
        if(xp%i) continue;
        yss[++yyn]=i;
        while(xp%i==0) xp/=i;
    }
    if(xp!=1) yss[++yyn]=xp;
    ll ans=1;
    while(1)
    {
        bool ok=1;
        for(int i=1;i<=yyn;i++)
        {
            ll y=yss[i];
            if(qp(ans,(x-1)/y,x)==1) {ok=0; break;}
        }
        if(ok) return pos=ans;
        ++ans;
    }
}
map<ll,int> bsgs_mp;
//find smallest x: a^x mod p=b
ll bsgs(ll a,ll b,ll p)
{
    if(b==0) return 1;
    map<ll,int>& ma=bsgs_mp;
    ma.clear();
    //only /2.5 for speed...
    ll hf=sqrt(p)/2.5+2,cur=b;
    for(int i=0;i<hf;i++)
        ma[cur]=i+1, cur=cur*a%p;
    ll qwq=1,qh=qp(a,hf,p);
    for(int i=0;;i++)
    {
        if(i)
        {
            if(ma.count(qwq))
                return i*hf-(ma[qwq]-1);
        }
        qwq=qwq*(ll)qh%p;
    }
    return 1e18;
}
//ax+by=1
void exgcd(ll a,ll b,ll& x,ll& y)
{
    if(b==0) {x=1; y=0; return;}
    exgcd(b,a%b,x,y);
    ll p=x-a/b*y; x=y; y=p;
}
template<class T>
T gcd(T a,T b) {if(b) return gcd(b,a%b); return a;}
//solve x^a mod p=b
vector<ll> kr(ll a,ll b,ll p)
{
    vector<ll> rst;
    if(!b) {rst.pb(0); return rst;}
    ll g=org_root(p);
    ll pb=bsgs(g,b,p);
    ll b1=a,b2=p-1,c=pb;
    ll gg=gcd(b1,b2);
    if(c%gg) return rst;
    b1/=gg, b2/=gg, c/=gg;
    ll x1,x2; exgcd(b1,b2,x1,x2);
    x1*=c; x1=(x1%b2+b2)%b2;
    ll cs=qp(g,x1,p),ec=qp(g,b2,p);
    for(ll cur=x1;cur<p-1;cur+=b2)
        rst.pb(cs), cs=cs*ec%p;
    sort(rst.begin(),rst.end());
    return rst;
}
int main(){
    int _;cin >> _;
    while(_--){
        int a, p, b;
        cin >> p >> a >> b;
        vector<ll> ans = kr(a,b,p);
        if(ans.size()){
            sort(ans.begin(),ans.end());
            for(auto i:ans)cout << i << " ";cout << endl;
        }else {
            cout << "No Solution"<<endl;
        }
    }
}