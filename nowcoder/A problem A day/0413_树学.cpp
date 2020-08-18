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
// #define int long long 
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
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260811, P_2=999998639;
void umax(int &a, int b) {if(a < b) a=b;}
void umin(int &a, int b) {if(a > b) a=b;}
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
const int N = 1e6 + 5;
struct Edge {
    int nxt, to;
} edge[N<<1];
int head[N], tot;
void add_edge(int u, int v) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    // edge[tot].w = w;
    head[u] = tot;
}

int dis[N], si[N], n, k;
void dfs(int u, int fa) {
    dis[u] = dis[fa] + 1;
    si[u] = 1;
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        si[u] += si[v];
    }
}
ll dp[maxn];
bool vis[maxn];
ll ans ;
void dfs2(int u , int fa){
    vis[u] = 1;
    // ans = min(ans, dp[u]);
    for(int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].to;
        if(v == fa) continue;
        dp[v] = 1ll * dp[u] - si[v] + (n-si[v]);
        // printf("sz[%d] == %d\n",v,si[v]);
        // printf("dp[%d] == %d\n",v,dp[v]);
        dfs2(v, u);
    }
}
int32_t main()
{
    close;
    cin >> n ;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y ,x);
    }
    dis[0] = -1;
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        dp[1] = dp[1] + 1ll* dis[i];
        // printf("dp[%d] == %d\n",i,dp[i]);
    }
        // printf("dp[%d] == %d\n",1,dp[1]);
    ans = dp[1];
    dfs2(1, 0);
    int ks = dp[1];
    for(int i = 1; i <= n; i++){
        umin(ks, dp[i]);
    }
    cout << ks << endl;
    // cout << ans << endl;
    // cout << *min_element(dp+1, dp+n+1);
}