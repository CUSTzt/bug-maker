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
#define int long long 
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%lld", &___T); for(int __CS=1;__CS<=___T;__CS++)
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
int a[maxn], n , k,vis[100];
int32_t main()
{
    CASET{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        std::vector<int > v;
        int zz = 1;
        memset(vis, 0, sizeof vis);
        v.eb(zz);
        while(zz<=1e16){
            zz = zz*k;
            if(zz<=1e16)v.eb(zz);
            else break;
        }
        int si = v.size();
        int fl = 0;
        for(int i = 1; i <= n; i++){
            int kp = si;
            if(a[i] == 0)continue;
            for(int j = si; j>=0;j--){
                if(a[i] >= v[j]&& !vis[j]){a[i]-=v[j];vis[j] = 1;}
                if(a[i] == 0)break;
            }
            if(a[i]){
                fl = 1;break;
            }
        }
        if(!fl){
            puts("YES");
        }else puts("NO");
    }
    
}