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
using LL = long long;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
int t , n , a[maxn];
namespace WORK{
    void work(){
        close;
        int mn = INF, mx = -INF;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            if(i == n-1)cout << i << endl;
            if(i > 0 && a[i] == -1 && a[i - 1] != -1)
			    mn = min(mn , a[i - 1]) , mx = max(mx , a[i - 1]);
            if(i < n-1 && a[i] == -1 && a[i+1] != -1) 
                mn = min(mn , a[i + 1]) , mx = max(mx , a[i + 1]);
        }
        int res = (mx + mn) / 2 ;
        cout << "mx === " << mx << "   mn === "<< mn << endl;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == -1){
                a[i] = res;
            }if(i){
                ans = max(ans , abs(a[i] - a[i-1]));
            }
        }
        cout << ans << ' ' << res << endl;
    }
}

int main()
{
    cin >> t;
    while(t--){
        WORK::work();
    }
}