#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
#define int long long 
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
int N , W, w[maxn],v[maxn],dp[105][100005];
int32_t main()
{
    cin >> N >> W;
    for(int i = 1; i <= N; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= W;j++){
            if(w[i] <= j){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
                // printf("dp[i-1][j-w[i]]+v[i] === %d\n",dp[i-1][j-w[i]]+v[i]);
                // printf("p[%d][%d]==%d\n",i,j,dp[i][j]);
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[N][W];
}