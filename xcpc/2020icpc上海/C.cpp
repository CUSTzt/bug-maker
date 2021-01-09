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
int dp[60][3][3][3], l[60], r[60], len, x, y;
int main()
{
    close;
    CASET{
        function<int (int ,int , int , int)> dfs = [&](int pos, int l1 , int l2 , int pre){
            // 由于i&j=0,所以(i+j)一定不会进位,log2(i+j)一定是他们的最高位1的位置.
            //令d[len][limit1][limit2][zero]表示:
            //当前长度为len,i的高位限制,j的高位限制,当前已枚举的值是否是0,的贡献.
            // printf("pos == %d   l1 === %d  l2 == %d  pre == %d\n",pos , l1 , l2 , pre);
            if(pos == -1) return 1;
            if(dp[pos][l1][l2][pre] != -1)return dp[pos][l1][l2][pre];
            int mx1 = l1 ? l[pos] : 1;
            int mx2 = l2 ? l[pos] : 1;
            int ans = 0;
            for(int i = 0; i <= mx1; i++){
                for(int j = 0; j <= mx2; j++){
                    if(i & j) continue;
                    int t = -1; //t是之后每个方案的贡献
                    if(pre &&(i||j)) t = pos+1;//当前位是最高位1,log+1
                    else t = 1;//当前位不是最高位1,那么只需要为最高位求方案数即可.
                    add(ans , dfs(pos-1,l1&&i==mx1,l2&&mx2==j, pre &&(!i&&!j))*t%mod);
                }
            }
            return dp[pos][l1][l2][pre] = ans;
        };
        auto solve = [&](){
            memset(dp , -1 , sizeof dp);
            len = 0;
            while(x || y) {
                // cout << "len == " << len << endl;
                l[len] = (x & 1);
                r[len] = (y & 1);
                x >>= 1, y >>= 1;
                len++;
            }
            int ans = dfs(len-1, 1, 1,1);
            // cout << "fuck" << endl;
            dec(ans , 1);
            return ans ;
        };
        cin >> x >> y;
        cout << solve() << endl;
    }
    return 0;
}