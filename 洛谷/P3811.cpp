 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年09月30日 星期一 18时51分42秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
#include<bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 5e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
ll inv[maxn];
ll n, p;
void inv_init(ll n ,ll p){
    inv[1] = 1;
    for(int i = 2; i <= n;i++){
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
}
int main(){
    cin >> n >> p;
    inv_init(n , p);
    for(int i =1; i <= n;i++)
        printf("%lld\n",inv[i]);
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
