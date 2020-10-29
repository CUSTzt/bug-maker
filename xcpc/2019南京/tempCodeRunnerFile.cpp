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
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
const double PI = acos(-1.0);
constexpr int maxn = 1000+10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9+7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260811, P_2=999998639;
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
template<class T>inline void umin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void umax(T &x, T y) {x = x < y ? y : x;}
template<class T>inline void dec(T &x, T y) {x -= y; if(x < 0) x += mod;}
template<class T>inline void add(T &x, T y) {x += y; while(x >= mod) x -= mod;}
int dx[] = {0, 0 , 1 , -1};
int dy[] = {1, -1 , 0 , 0};
int n , m, a[maxn][maxn];
int in[maxn][maxn], out[maxn][maxn], dp[maxn][maxn][maxn], ans;
int chk(int x, int y){
    if(x <= 0 || x > n || y <= 0 || y > m) return 1;
    return 0;
}
void calc(int i , int j , int xx , int yy){
    add(dp[xx][yy][2], dp[i][j][1]);
    add(dp[xx][yy][3], dp[i][j][2]);
    add(dp[xx][yy][4], dp[i][j][3]+dp[i][j][4]);
}
int main()
{
    close;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    queue<pii> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < 4; k++){
                int xx = dx[k] + i , yy = dy[k] + j;
                if(chk(xx, yy))continue;
                if(a[xx][yy] == a[i][j] + 1) out[i][j] ++;
                if(a[xx][yy] == a[i][j] - 1) in[j][i]--;
            }
            if(in[i][j] == 0){
                q.push({i , j});
                dp[i][j][1] ++;
            }
        }
    }
    while(q.size()){
        pii fr = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = fr.fi + dx[i], yy = fr.se + dy[i];
            if(chk(xx , yy))continue;
            if(a[xx][yy] != a[fr.fi][fr.se] + 1)continue;
            calc(fr.fi, fr.se, xx, yy);
            in[xx][yy]--;
            if(in[xx][yy] == 0) q.push({xx, yy});
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            add(ans, 1ll*dp[i][j][4]);
        }
    }
    cout << ans << endl;
}