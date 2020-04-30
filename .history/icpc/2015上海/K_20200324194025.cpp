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
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
char a[maxn];
int dp[100050];
int main()
{
    CASET{
        scanf("%s",a+1);
        int len = strlen(a+1);
        for(int i = 0; i <= len+10;i++){
            dp[i] = 0;
        }
        vector<int > v;
        v.eb(0);
        int zz = 1;
        ll mx = 0;
        dp[1] = 1;
        for(int i = 2; i <= len; i++){
            if(a[i] != a[i-1]){
                v.eb(zz);
                mx += 1ll * zz * zz ;
                zz = 1;
                dp[i] == zz;
            }else {
                zz++;
                dp[i] = zz;
            }
        }
        v.eb(zz);
        v.eb(0);
        mx += 1ll*zz*zz;
        ll MX = mx;
        int cnt = 1;
        for(int i = 1; i <= len; i++){
            if(dp[i] == 1){
                MX = max(MX, mx-v[cnt])
            }
        }
        printf("Case #%d: %lld\n",__CS,MX);
    }
    
}