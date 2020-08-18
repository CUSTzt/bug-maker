#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long LL;
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define eps 1e-8
typedef long long ll;
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const int N = 125;
int n , m , k , vis[N], match[N];
vector<int>g[N];
int dfs(int x){
    for(auto y : g[x]){
        if(vis[y]) continue;
        vis[y] = 1;
        if(!match[y] || dfs(match[y])){
            match[y] = x; return 1;
        }
    }
    return 0;
}
int main()
{
    while(cin >> n && n){
        cin >> m >> k;
        for(int i = 1; i <= n+10; i++){
            g[i].clear();
        }
        for(int i = 1; i <= k; i++){
            int j , u , v;
            cin >> j >> u >> v;
            if(v && u) g[u].push_back(v);
        }
        int ans = 0;
        memset(match , 0  , sizeof match);
        for(int i = 1; i < n; i++){
            memset(vis , 0 , sizeof vis);
            ans+=dfs(i);          
        }cout << ans << endl;
    }   
}