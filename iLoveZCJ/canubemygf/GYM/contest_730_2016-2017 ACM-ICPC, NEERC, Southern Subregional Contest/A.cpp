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
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 110+10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9+7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260811, P_2=999998639;
void umax(int &a, int b) {if(a < b) a=b;}
void umin(int &a, int b) {if(a > b) a=b;}
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
int r[maxn];
int mp[maxn*maxn][maxn], n , x;
pii a[maxn];
int main()
{
    close;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = {x, i};
    }
    int cnt = 0;
    while(1){
        sort(a+1, a+1+n);
        if(a[1].first == a[n].first) break;
        cnt++;
        int m = 0;
        for(int i = 1; i <= n; i++){
            if(a[i].first > a[1].fi) m++;
        }
        if(m > 1 && m <= 5 && a[n].fi - 1 == a[1].fi){
            for(int i = n - m + 1; i <= n; i++){
                a[i].first--;
                mp[cnt][a[i].second] = 1;
            }
            break;
        }
        else{
            if(a[n].first)a[n].first -- ;
            if(a[n-1].first) a[n-1].first --;
            mp[cnt][a[n].second]=1; 
            mp[cnt][a[n-1].se] = 1;
        }
    }
    cout << a[1].first << endl << cnt << endl;
    for(int i = 1; i <= cnt ; i++){
        for(int j = 1; j <= n; j++){
            cout << mp[i][j];
        }cout << endl;
    }
}