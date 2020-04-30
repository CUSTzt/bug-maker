/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-06 11:22:28
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , k , l[maxn], r[maxn];
double dp[maxn][maxn];
ll Cnt(double n){
    ll ans = 0, x = 1, cnt = 0, high , num = n;
    while(num){
        high = num % 10 ;
        
    }
}
int32_t main()
{
    close;
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> l[i] >> r[i];
    }
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/