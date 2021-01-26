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
constexpr int maxn = 1e3+10; // remember to calculate. if tle, check maxn first.
int dx[] = {1, -1, 0 , 0};
int dy[] = {0, 0, -1 , 1};
int vis[maxn][maxn];
int main()
{
    ll n;
    // cout << a(n) = a(-n-4) = 1 + ( 3*n*(n + 4) + 2 - (-1)^n*(n*(n + 4) + 2) )/8 << endl;
    cin >> n;
    if(n & 1){
        cout << 1ll + ( 3*n*(n + 4) + 2 + (n*(n + 4) + 2) )/8 << endl;
    }else {
        cout << 1ll + ( 3*n*(n + 4) + 2 - (n*(n + 4) + 2) )/8 << endl;
    }
    /*queue<tuple<int , int , int, int> > que;
    int step;
    cin >> step;
    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            ans += vis[i][j];
        }
    }
    que.push({100, 100, -1, 0});
    while(not que.empty()){
        auto [x, y , fx, stp] = que.front();
        que.pop();
        // cout << x << ' ' << y <<  ' ' << fx << " " << stp << endl;
        for(int i = 0; i < 4; i++){
            if(stp == step){
                vis[x][y] = 1;
                // break;
                // cout << vis[x][y] << endl;
                continue;
            }
            if(i == 0 || i == 1) {
                if(fx == 0 || fx == 1) {
                    continue;
                }
                int xx = dx[i] + x, yy = dy[i] + y;
                que.push({xx, yy , i , stp+1});
            }else {
                if(fx == 2 || fx == 3) {
                    continue;
                }
                int xx = dx[i] + x, yy = dy[i] + y;
                que.push({xx, yy , i , stp+1});
            }
        }
    }
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            ans += vis[i][j];
        }
    }
    cout << ans << endl;*/
    return 0;
}
/*
4,4,12,9,24,16,40
*/