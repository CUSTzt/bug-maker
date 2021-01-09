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
#include <bitset>
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
#define SZ(a) int32_t(a.size())
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
constexpr int maxn = 3000+10; // remember to calculate. if tle, check maxn first.
int n , m, d[maxn][maxn];
char s[maxn][maxn];
int dx[] = {1,0,0,-1}, dy[] = {0,-1,1,0};
pii pre[maxn][maxn];
void print(int x, int y){
    if(!x) return ;
    auto [i, j] = pre[x][y];
    print(i , j);
    if(j == y) putchar(i < x ? 'D' : 'U');
    if(i == x) putchar(j < y ? 'R' : 'L');
}
int main()
{
    // close;
    cin >> n >> m;
    memset(d, 0xff, sizeof d);
    queue<pii> q;
    int stx, sty, edx, edy;
    for(int i = 1; i <= n; i++){
        cin >> (s[i] + 1);
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 'S'){
                d[i][j] = 0 , q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        if(s[x][y] == 'E'){
            cout << d[x][y] << endl;
            print(x, y);
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int xx = dx[i] + x, yy = dy[i] + y;
            while(xx >= 1 && yy >= 1 && xx <= n && yy <= m && s[xx][yy] == 'X'){
                xx += dx[i], yy +=dy[i];
            }
            if(xx < 1 || yy < 1 || xx > n || yy > m){
                continue;
            }
            if(d[xx][yy] == -1){
                d[xx][yy] = d[x][y] + 1;
                pre[xx][yy] = {x, y};
                q.push({xx, yy});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}