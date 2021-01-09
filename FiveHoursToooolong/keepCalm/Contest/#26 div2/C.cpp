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
char s[300][300];
int main()
{
    int n , m , a, b , c;
    cin >> n >> m >> a >> b >> c;
    if((n * m ) & 1){
        return cout << "IMPOSSIBLE" , 0;
    }
    //others
    if(n & 1) a -= m/2;
    if(m & 1) b -= n/2;
    if(a < 0 || b < 0){
        return cout << "IMPOSSIBLE" , 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            s[i][j] = (i / 2 % 2 == j / 2 % 2) ? 'a' : 'b';
        }
    }
    // 形成四个四个aa aa/ bb bb一坨的
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << s[i][j];
    //     }cout << endl ;
    // }  
    c -= (n / 2) * (m / 2);
    for(int i = 0; i < n - n % 2; i += 2){
        for(int j = 0; j < m - m % 2; j += 2){
            if(c < 0){
                if(a > 1){
                    c++;
                    a-=2;
                    s[i][j] = s[i][j+1] += 2;
                }else if (b > 1){
                    c++;
                    b-=2;
                    s[i][j] = s[i+1][j] += 2;
                }else {
                    return cout << "IMPOSSIBLE" , 0;
                }
            }
        }
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            cout << s[i][j];
        }cout << endl;
    }
}