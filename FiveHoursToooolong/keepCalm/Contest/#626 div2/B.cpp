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
int n , m , k , a[maxn], b[maxn ];
vector<int >v;
int32_t main()
{
    close;
    cin >> n >> m >> k;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    for(int i = 1; i*i <= k; i++){
        if(k % i == 0){v.eb(i);}
    }
    int ans = 0;
    sort(v.begin(),v.end());
    int si = v.size();
    vector<int >aa(n+1,0);
    vector<int >bb(m+1,0);
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            res=0;
        }else {
            res++;
            aa[res]++;
        }
    }
    res=0;
    for(int i = 1; i <= m; i++){
        if(b[i] == 0){
            res=0;
        }else {
            res++;
            bb[res]++;
        }
    }
    
    for(int i = m; i>1;i--){
        bb[i-1]+=bb[i];
    }
    for(int i = n; i>1;i--){
        aa[i-1]+=aa[i];
    }
    // for(auto it : aa)cout << it << ' ';cout << endl;
    // for(auto it : bb)cout << it << ' ';cout << endl;
    // int ans = 0;
    for(int i = 0; i < v.size();i++){
        int x = v[i], y = k / v[i];
        if(x == y){
            if(n  >= x && m >= y)ans-=aa[y]*bb[x];
        }
        if(n >= x && m >= y){
            ans+=aa[x]*bb[y];
        }
        if(n >= y && m>= x)ans+=aa[y]*bb[x];
    }
    cout << ans << endl;
}