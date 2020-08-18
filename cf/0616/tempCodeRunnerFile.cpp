//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define int long long 
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define SZ(a) int(a.size())
#define ALL(x) (x).begin(),(x).end()
#define trav(a,x) for (auto& a: x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9+7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260811, P_2=999998639;
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
template<class T>inline void umin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void umax(T &x, T y) {x = x < y ? y : x;}
template<class T>inline void dec(T &x, T y) {x -= y; if(x < 0) x += mod;}
template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}

void up(){
    int k;
    cin >> k;
    vi c(k+10), d(k+10), m(k+10), p(k+10), e(k+10), R(k+10), E(k+10);    
    for(int i = 1; i <= k; i++){
        cin >> c[i] >> d[i] >> m[i] >> p[i];
    }
    for(int i = 1; i < k; i++){
        cin >> e[i] >> R[i] >> E[i];
    }
    for(int i = 1; i <= k; i++){
        E[i] += E[i-1];
    }
    int kp = 0;
    for(int i = 1; i <= k ; i++){
        kp += p[i];
        if(kp < d[i]){
            cout << -1 << endl;
            return ;
        }
        kp -= d[i];
        umin(kp , e[i]);
    }
    int ans = 0 , tot = 0;
    for(int i = 2; i <= k; i++){
        umin(c[i], c[i-1] + R[i-1]);
    }
    map<int , int > mp;
    for(int i = 1; i <= k; i++){
        int pp = m[i]+c[i]-E[i-1];
        int pt = p[i]-d[i];
        mp[pp] += p[i], tot += pt;
        while(d[i]){
            auto [u , v] = *mp.begin();
            if(v > d[i]){
                ans += (u+E[i-1]) * d[i];
                mp[u] -= d[i];
                d[i] = 0;
            }else {
                ans += (u + E[i-1]) * v;
                d[i] -= v;
                mp.erase(mp.begin());
            }
        }
        if(tot <= e[i])continue;
        int tmp = tot - e[i];
        tot = e[i];
        while(tmp){
            auto [u , v] = *mp.rbegin();
            if(v > tmp){
                mp[u] -= tmp;
                tmp = 0;
            }else {
                tmp -= v;
                mp.erase(u);
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    CASET{
        up();
    }
    
}