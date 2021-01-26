//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
constexpr int mod = 1e9+7; // 998244353
// mt19937 dlsrand(random_device{}());
// mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
// int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll ex_gcd(ll a, ll b, ll& x, ll& y){if(!b){x=1;y=0;return a;}ll ret=ex_gcd(b,a%b,y,x);y-=a/b*x;return ret;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
int norm(int x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline ll get_inv(ll a) { ll x, y; ex_gcd(a, mod, x, y); return norm(x + mod);}
template<class T>inline void umin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void umax(T &x, T y) {x = x < y ? y : x;}
template<class T>inline void dec(T &x, T y) {x -= y; if(x < 0) x += mod;}
template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260817, P_2=999998639;
constexpr int maxn = 1e6+10; // remember to calculate. if tle, check maxn first.
void up(){
    int n , m, l , r;
    cin >> n >> m;
    string s;
    cin >> s;
    s = "%"+s;
    vi a(n+10),sum(n+10);
    for(int i = 1; i <= n; i++){
        a[i] = (s[i] == '+' ? 1 : -1); 
        sum[i]+=a[i]; 
    }
    vector<pii> pre, suf;
    pre.eb(0,0);
    int x = 0;
    for(int i = 1; i <= n; i++){
        x += a[i];
        pii tp = pre[i-1];
        // pre.push_back(tp);
        umin(tp.fi, x), umax(tp.se, x);
        pre.push_back(tp);

    }
    suf.resize(n+10);
    for(int i = n; i >= 1; i--){
        if(i == n){
            suf[i] = make_pair(sum[i], sum[i]);
        continue;
        }
        pii tp = suf[i+1];
        umin(suf[i].fi, sum[i]),umax(suf[i].se,sum[i]);
    }
    while(m--){
        cin >> l >> r;
        ll ans1 = pre[l-1].fi , ans2 = pre[l-1].se, now = sum[l-1];
        if(r==n){
            cout << ans2-ans1+1 << endl;
            continue;
        }
        umin(ans1,now+suf[r+1].fi-sum[r]), umax(ans2,now+suf[r+1].se-sum[r]);
            cout << ans2-ans1+1 << endl;    
    }
    // int x = 0;
    // vi suf(n+10), pre(n+10);
    // string t(s);
    // for(int i = 1; i <= n; i++){
    //     t[i] = '+'+'-' - t[i];
    // }
    // // cout << t << endl;
    // pre[0 ] = 0;
    // for(int i = 1; i <= n; i++){
    //     x += (s[i] == '+' ? 1 : -1);
    //     pre[i] = x;
    // }
    // x = 0;
    // suf[n+1] = 0;
    // for(int i = n; i >= 1; i--){
    //     x += (t[i] == '+' ? 1 : -1);
    //     suf[i] = x;
    // }
    // vi mnpre(n+10), mxpre(n+10), mnsuf(n+10), mxsuf(n+10);
    // mnpre[0] = INF, mxpre[0] = -INF, mnsuf[n+1] = INF, mxsuf[n+1] = -INF;
    // for(int i = 1; i <= n; i++){
    //     umax(mxpre[i], max(mxpre[i - 1], pre[i]));
    //     umin(mnpre[i], min(mnpre[i - 1], pre[i]));
    // }
    // for(int i = n; i >= 1; i--){
    //     umax(mxsuf[i], max(mxsuf[i+1], suf[i]));
    //     umin(mnsuf[i], min(mnsuf[i+1], suf[i]));
    // }
    // mnpre[0] = 0, mxpre[0] = -0, mnsuf[n+1] = 0, mxsuf[n+1] = -0;
    // while(m--){
    //     int l , r;
    //     cin >> l >> r;
    //     l--, r++;
    //     // int mxx = max({mxpre[l], mxsuf[r], mxsuf[r] + mxpre[l]});
    //     // int mnn = min({mnpre[l], mnsuf[r], mnpre[l] + mxsuf[r]});
    //     int mxx = max(mxpre[l], pre[l] + mxpre[r]);
    //     int mnn = min(mnpre[l], pre[l] + mnpre[l]);
    //     cout << mxx - mnn + 1 << endl;
    // }
}
int32_t main()
{
    close;
    CASET{
        up();
    }
    return 0;
}
/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
                    - William Butler Yeats
*/