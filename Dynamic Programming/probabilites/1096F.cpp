//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ 火影三板斧
// #pragma GCC target ("avx2,fma")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
#include <algorithm>
#include <cassert>
#include <bits/stdc++.h>
#include <functional>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define int LL
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int32_t(a.size())
#define ALL(x) (x).begin(),(x).end()
#define trav(a,x) for (auto& a: x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr),cout<<fixed<<setprecision(10)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
constexpr int mod = 998244353;
// mt19937 dlsrand(random_device{}());
// mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
// int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll ex_gcd(ll a, ll b, ll& x, ll& y){if(!b){x=1;y=0;return a;}ll ret=ex_gcd(b,a%b,y,x);y-=a/b*x;return ret;}
LL mul(LL u, LL v, LL p) { return (u * v - LL((long double) u * v / p) * p + p) % p; }
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
int norm(int x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline ll get_inv(ll a) { ll x, y; ex_gcd(a, mod, x, y); return norm(x + mod);}
template<class T>inline void umin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void umax(T &x, T y) {x = x < y ? y : x;}
template<class T>inline void dec(T &x, T y) {x -= y; if(x < 0) x += mod;}
template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}
template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &first, Args& ... args) { read(first); read(args...); }
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260817, P_2=999998639;
constexpr int maxn = 1e6+10; // remember to calculate. if tle, check maxn first.
/*
    所谓的 永远 是 ‘三年’  三年也真的好长好长啊
    爱，
    不是魔法了
    对吗？
*/
struct BIT {
    static const int N = 1e6+10;
    ll c[N];
    int lowbit(int x) {return x & (-x);}
    void add(int x, ll v) {
        for(; x < N; x += lowbit(x)) c[x] += v;
    }
    ll query(int x) {
        ll res = 0;
        for(; x; x -= lowbit(x)) res += c[x];
        return res;   
    }
    ll query(int l, int r) {
        return query(r) - query(l - 1);   
    }
    void modify(int x, ll v) {
        ll pre = query(x, x);
        ll d = v - pre;
        add(x, d);
    }
}bit;
int n, vis[maxn],cnt , b[maxn], a[maxn], ans , tot;
LL invf[maxn], fac[maxn];
void fac_inv_init(LL n, LL p) {
    fac[0] = 1;
    FOR (i, 1, n)
        fac[i] = i * fac[i - 1] % p;
    invf[n - 1] = bin(fac[n - 1], p - 2, p);
    FORD (i, n - 2, -1)
        invf[i] = invf[i + 1] * (i + 1) % p;
}
inline LL C(LL n, LL m) { // n >= m >= 0
    return n < m || m < 0 ? 0 : fac[n] * invf[m] % mod * invf[n - m] % mod;
}
int32_t main()
{
    close;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != -1) vis[a[i]] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) {
            b[++cnt] = i;
        }
    }
    fac_inv_init(maxn, mod);
    sort(b+1, b+1+cnt);
    int v = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] != -1){
            int Less = bit.query(a[i]);
            add(ans, (tot-Less)*fac[cnt]%mod); // 已知+已知
            int pos = lower_bound(b+1,b+cnt+1, a[i])-b;
            pos--;
            add(ans,pos*(cnt-v)%mod*fac[cnt-1]%mod); //已知+未知
            add(ans,(cnt-pos)*v%mod*fac[cnt-1]%mod);//未知+已知
            tot++;
            bit.add(a[i],1);
        }else{
            v++;
        }
    }
    int INV4 = get_inv(4);
    add(ans,cnt*(cnt-1)%mod*INV4%mod*fac[cnt]%mod); //未知+未知
    cout << ans*get_inv(fac[cnt])%mod<< endl;
    return 0;
}
/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
                    - William Butler Yeats
*/