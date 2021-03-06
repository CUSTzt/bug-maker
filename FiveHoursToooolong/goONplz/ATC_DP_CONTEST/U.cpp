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
constexpr int maxn = 17;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
int  a[maxn][maxn], n;
ll dp[1 << maxn], s[ 1<< maxn];
int main()
{
    cin >> n ;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cin >> a[i][j];
        }
    }
    int end = 1 << n;
    for(int t = 0; t < end ; t++){
        ll cnt  = __builtin_popcount(t);
        vector<int > v;
        for(int i = 0; i < n; i++){
            if((t>>i) & 1)v.eb(i);
        }
        ll zz = 0ll;
        for(int i = 0; i < cnt ; i++){
            for(int j = i+1; j < cnt ; j++){
                zz += a[v[i]][v[j]];
            }
        }
        dp[t] = s[t] = zz;
    }
    for(int i = 0; i < end; i++){
        for(int j = i; j ; j=(j-1) & i){
            dp[i] = max(dp[i], dp[i^j] + s[j]);
        }
    }
    cout << dp[end - 1];
}
