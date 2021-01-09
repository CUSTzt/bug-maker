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
constexpr int maxn = 1e6+10; // remember to calculate. if tle, check maxn first.

/*
 CF 1451F - 博弈
    题意：给定一个N*M大小的棋盘，每个格子上都有一个数字，每一次可以选择两个点(x1, y1), (x2, y2)
                且x2>=x1, y2>=y1, 即(x2, y2)在(x1, y1)的右下方，每次操作可以选择从(x1, y1)到(x2, y2)的一条曼哈顿路径，
                (x1, y1)必须要减去一个正数，这条路径上的其他数字可加可减可不变，A, B两人轮流进行这样的操作，最后所有数字都为0后结束，
                问谁必赢
    思路：状态太多了，而且操作也太灵活了，SG肯定是没有用的，对于这种状态数没法枚举的题，可以将状态变成，对立的一些状态集合，
                将所有的状态归纳到状态集合中去，然后转化为状态集合之间的转化，若能让某一方一直在必败状态所在的状态集里出不来，那么就可以判断胜负了
    做法：设斜对角线上的所有元素的异或值为Xor(x+y==d) 
                设状态S为对于任意d，Xor(x+y==d)=0
                状态Q为存在d，Xor(x+y==d)!=0
                对于任意一种棋盘上的数字状态，只有可能属于S或Q
                证明: S状态操作一步后，必然转移到Q状态：显然，(x1, y1)减去某个整数后Xor(x1+y1==d)!=0
                证明：Q状态存在一种操作转移到S状态：对于一组数，若它们的异或值不为0，总能选择其中的一个数，让其变小后，使整个的异或值为0(证明略)
                败局属于S集合
                若初始状态为Q先手总可以把S留给后手，后手不得不把Q还给先手，那么后手一直在S态，则最后必输
*/

int f[110*2];
int main()
{
    CASET{
        int n , m , t;
        memset(f, 0 , sizeof f);
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> t;
                f[i+j] ^= t;
            }
        }
        int fl = 1;
        for(int i = 1; i <= n + m; i++){
            if(f[i] != 0){
                fl = 0;
            }
        }
        cout << (fl ? "Jeel" : "Ashish") << endl;
    }
    return 0;
}