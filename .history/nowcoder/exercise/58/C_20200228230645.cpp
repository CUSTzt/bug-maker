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
int a[20][20], n , m , k,tot,sum[20];
bool check(int x){
    if(x <= n || x <= m)return true;
    return false;
}
int main()
{
    cin >>n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            tot+=a[i][j];
        }
    }
    if(check(k)){
        cout << tot << endl;
        return 0;
    }
    int ans = -INF;
    for(int i = 0; i < 1<<m; i++){
        memset(sum , 0 , sizeof sum);
        int res = 0;
        for(int j = 1; j <= n; j++){
            for(int k = 0; k< m; k++){
                if(1 << k & i)res+=a[j][k+1];
                else sum[j]+a[j][k+1];
            }
        }sort(sum+1, sum+n+1,greater<int >());
        for(int j = 1; j <= k - __builtin_popcount(i);j++){
            res+=sum[j];
        }ans = max(ans , res);
    }cout << ans << endl;
}