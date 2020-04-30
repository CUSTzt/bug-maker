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
#define int unsigned long long 
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
int n , m , p;//,a[maxn],b[maxn];
int32_t main()
{
    close;
    cin >> n >> m >> p;
    vector<int >a,b;
    a.resize(n),b.resize(m);
    for(int i = 0; i < n;i++)cin >> a[i];
    for(int i = 0;i < m; i++)cin >> b[i];
    //int aa = n-1, bb = m-1,ans = a[n-1]*a[m-1], zz = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int zz = 0;
    map<int,int  > mpp;
    //for(int i = 0; i <= n+m-2;i++){
    while(1){
        int i = (rnd(n+m-1)+rnd(n+m-1))%(n+m-1);
        if(mpp.count(i))continue;
        else mpp[i]++;
        int ans = 0;
        for(int j = max(0ull,i-m); j <= min(i,n-1);j++){
            //if(j >= n || i-j >= m)break;
            if(i<n&&(i-j<=m-1))ans+= a[j]*b[i-j];
            // cout << " j === " <<j << endl;
            // cout << "ans === " << ans << endl;
            if(ans >= 1e18)ans%=p;
        }
        if(ans % p){zz=i;/*cout << "ans === " << ans << endl;*/break;}
    }
    cout << zz << endl;
}