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
#define int long long 
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
struct node{
    int x, y,zz;
}a[maxn];
int n;
int cmp(node a, node b){
    return a.zz < b.zz;
    //return a.y*abs(a.x-a.y)*abs(a.x-a.y) < b.x*abs(b.x-b.y)*abs(b.x-b.y);
}
int32_t main()
{
    close;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].zz = a[i].y*(a[i].y-a[i].x)*(a[i].y-a[i].x);
        cout << " i == " << i << "   zz===" << a[i].zz << endl;
    }
    sort(a, a+n, cmp);
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ans+=1ll*abs(a[i].zz-a[i-1].zz);
        //ans+=abs(a[i].y*(a[i].y-a[i].x)*(a[i].y-a[i].x) - a[i-1].y*(a[i-1].x-a[i-1].y)*(a[i-1].x-a[i-1].y));
    }cout << ans << endl;
}