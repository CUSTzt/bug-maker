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
/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-29 13:03:50
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
/*#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
//#define int long long 
typedef long long ll;
const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
const int MAXN = 2; //几维就写几   不要多1的
ll m[MAXN][MAXN]={
    {1 , 1},
    {1 , 0}        
};
struct Matrix
{
    ll mat[MAXN][MAXN];
    Matrix() {}
    Matrix operator*(Matrix const &b)const
    {
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                for (int k = 0; k < MAXN; k++)
                    res.mat[i][j] = (res.mat[i][j]+this->mat[i][k] * b.mat[k][j])%mod;
        return res;
    }
}A;
Matrix pow_mod(Matrix base, ll n)
{
    Matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    for (int i = 0; i < MAXN; i++)
        res.mat[i][i] = 1;
    while (n > 0){
        if (n & 1) res = res*base;
        base = base*base;
        n >>= 1;
    }
    return res;
}
bool prime[maxn];
int p[maxn], k, cnt , c;
ll num[maxn], pri[maxn],fac[maxn];
void isprime(){
    k = 0;
    memset(prime , true , sizeof(prime));
    for(int i = 2; i <= maxn; i++){
        if(prime[i]){
            p[k++] = i;
            for(int j = i+i; j < maxn; j+=i)
                prime[j] = false;
        }
    }
}
ll legendre(ll a, ll p){ // 判断a = 5是不是p的剩余系
    if(bin(a , (p-1) / 2, p) == 1)return 1;
    return -1;
}
void get_factor(ll n ,ll pri[], ll num[]){
    cnt = 0;
    ll mm = sqrt(n+0.5);
    for(int i = 0; p[i] <= mm; i++){
        if(n % p[i] == 0){
            int a = 0;
            pri[cnt] = p[i];
            while(n % p[i] == 0){
                a++;n /= p[i];
            } num[cnt++] = a;
        }
    }
    if(n > 1){
        pri[cnt] = n;
        num[cnt++] = 1;
    }
}
void get_factor2(ll n){
    c = 0;
    ll t = sqrt(0.5 + n);
    for(int i = 1; i <= t; i++){
        if(n % i == 0){
            if(i * i == n)fac[c++] = i;
            else {
                fac[c++] = i;fac[c++] = n/i;
            }
        }
    }
}
ll find_loop(ll n){
    get_factor(n , pri , num);
    ll ans = 1; 
    for(int i = 0 ; i < cnt ; i++){
        ll record = 1;
        if(pri[i] == 2){
            record = 3;
        }else if(pri[i] == 3){
            record = 8;
        }else if(pri[i] == 5){
            record = 20;
        }else {
            if(legendre(5, pri[i]) == 1){
                get_factor2(pri[i] - 1);
            }else get_factor2(2*pri[i]+2);
            sort(fac, fac + c);
            for(int k = 0; k < c; k++){
                mod = pri[i];
                Matrix tmp = pow_mod(A, fac[k] - 1);
                ll x = (tmp.mat[0][0]  + tmp.mat[0][1] % mod) % mod;
                ll y = (tmp.mat[1][0]  + tmp.mat[1][1] % mod) % mod;
                if(x == 1 && y == 0){
                    record = fac[k];break;
                }
            }
        }
        for(int k = 1; k < num[i]; k++){
            record *= pri[i];
        }
        ans = ans / __gcd(ans, record) * record;
    }
    return ans;
}
int32_t main()
{
    ll n;
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            A.mat[i][j] = m[i][j];
        }
    }
    isprime();
    int ps = 1;//cin >> ps;
    while(ps--){
        int moood;
        cin >> n; cin >> moood;
        cout << find_loop(n) % moood << endl;
    }
    //system("pause");
}*/
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/
/*
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using LL = long long;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
unordered_map<int , int > mp;
typedef pair<int , int> pii;*/