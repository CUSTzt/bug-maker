/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-06 13:05:23
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long 
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
double dp[maxn], p[maxn];
int n;
ll cnt(ll n){
    ll num = n,cnt , x=1, high;
    while(num){
        high = num % 10 ;
        num /= 10;
        cnt++;
    }for(int i = 1; i < cnt; i++){
        x *= 10;
        ans += 10;
    }
    
}
int32_t main()
{
    
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/