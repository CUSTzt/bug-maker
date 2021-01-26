//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ 火影三板斧
// #pragma GCC target ("avx2,fma")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
#include <algorithm>
#include <cassert>
#include <bits/stdc++.h>
#include <functional>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define int LL
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
constexpr int maxn = 8e6+10; // remember to calculate. if tle, check maxn first.
/*
    所谓的 永远 是 ‘三年’  三年也真的好长好长啊
    爱，
    不是魔法了
    对吗？
*/

/*
 *题意：
 *给出一个数组，询问一个最小的值x，使得这个数组的所有元素异或x后逆序对最少
 *考虑贪心做法，从低位到高位构造x
 *每次比较x的第i位是1和x的第i位是0所形成的数组的逆序对数量，选择少的那一个
 *可以将每个数的二进制形式高位到低位存到一个字典树里
 *两个数的大小取决于他们二进制位上第一个不同的位
 *可以单独考虑字典树的其中一个子树，设它的左子树为l，右子树为r，那么l里面的所有数一定是比r小的
 *可以枚举l里面有多少数的下标比r里面的数的下标小，这样一个子树内的逆序对数量就统计完了
 *然后将所有子树以此合并，最后根节点得到的是所有逆序数的数量
 
 *接下来考虑贪心构造x的这个过程
 *假设当前贪心到x的第i位，这一位是1，那么对应层数的子树要反转
 *开一个dp数组分别统计翻转和不翻转的逆序对数量
 *就完成了这个贪心的过程
 */ 
int dp[maxn][2], tot, trie[maxn][2];
vi g[maxn];
void insert(int x , int p){
    int u = 0;
    for(int i = 29; i>=0; i--){
        int bit = ((x >> i) & 1);
        if(!trie[u][bit]) trie[u][bit] = ++tot;
        u = trie[u][bit];
        g[u].eb(p);
    }
}
void dfs(int u ,int dep){
    if(trie[u][0]) dfs(trie[u][0], dep-1);
    if(trie[u][1]) dfs(trie[u][1], dep-1);
    if(!trie[u][0] || !trie[u][1]) return ;
    ll sum = 0, tt = 0;
    for(int i = 0; i < g[trie[u][0]].size(); i++){
        while(tt < g[trie[u][1]].size() and g[trie[u][1]][tt] < g[trie[u][0]][i]) tt++;
        sum+=tt;
    }
    dp[dep][0]+=sum;
    dp[dep][1] += 1ll * g[trie[u][0]].size()*g[trie[u][1]].size()-sum;
}
int32_t main()
{
    close;
    int n;
    cin >> n;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        insert(x, i);
    }
    dfs(0, 29);
    ll ans = 0, u = 0;
    for(int i = 0; i <= 29; i++){
        ans += min(dp[i][0],  dp[i][1]);
        if(dp[i][1] < dp[i][0]) u += 1ll<<i;
    }
    cout << ans << " " << u << endl; 
    return 0;
}
/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
                    - William Butler Yeats
*/