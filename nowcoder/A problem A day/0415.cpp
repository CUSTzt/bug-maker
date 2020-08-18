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
#define endl '\12'
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
constexpr int mod = 1e9+7;
constexpr int Erica = 998244353;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll ex_gcd(ll a, ll b, ll& x, ll& y){if(!b){x=1;y=0;return a;}int ret=ex_gcd(b,a%b,y,x);y-=a/b*x;return ret;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
int norm(int x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline ll get_inv(ll a) { ll x, y; ex_gcd(a, mod, x, y); return norm(x + mod);}
template<class T>inline void umin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void umax(T &x, T y) {x = x < y ? y : x;}
template<class T>inline void dec(T &x, T y) {x -= y; if(x < 0) x += mod;}
template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260817, P_2=999998639;
namespace solve1
{
    int n, x, y, dep[maxn];
    vector<int> v[maxn];
    void dfs(int u , int fa){
        for(auto v : v[u]){
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v , u);
        }
    }
    void up(){
        cin >> n;
        for(int i = 1; i < n; ++i){
            cin >> x >> y;
            v[x].eb(y), v[y].eb(x);
        }
        dfs(1, 0);
        ll odd =  0 , even = 0;
        for(int i = 1; i <= n; i++){
            if(dep[i] & 1) odd++;else even++;
        }
        cout << (1ll*odd*(odd-1)/2)+(1ll*even*(even-1)/2) << endl;
    }
} // namespace solve1
namespace solve2
{
    const int N = 3e5 + 10;
    struct Edge {
        int nxt, to, w;
    } edge[N << 1];
    int head[N], tot;
    void add_edge(int u, int v, int w) {
        edge[++tot].nxt = head[u];
        edge[tot].to = v;
        edge[tot].w = w;
        head[u] = tot;
    }
    
    ll f[N][2] , ans;
    void dfs(int u , int fa){ //设f[i][0/1]表示以i为根的子树中，与根节点i的距离为偶数(0)奇数(1)的点的数量。
        f[u][0] = 1;
        for(int i = head[u]; i ; i = edge[i].nxt){
            int v = edge[i].to;
            if(v == fa) continue;
            dfs(v , u);
            ans += f[v][1] * f[u][0];
            ans += f[v][0] * f[u][1];
            f[u][0] += f[v][1];
            f[u][1] += f[v][0];
        }
    }
    void up(){
        int n, x, y ;
        cin >> n; 
        for(int i = 1; i < n; i++){
            cin >> x >> y;
            add_edge(x ,y , 1), add_edge(y , x, 1);
        }
        dfs(1 , 0);
        cout << ans << endl;
    }
} // namespace solve2

int main()
{
    solve2::up();
    return 0;
}