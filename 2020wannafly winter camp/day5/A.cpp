/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-16 16:36:47
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long 
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
bool isprime(int x){
    int m = sqrt(x + 0.5);
    for(int i = 2; i <= m; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int32_t main()
{
    cout << isprime(10000609) << endl;
    freopen("prime.txt","w",stdout);
    int cnt = 0;
    for(int i = 2;i <= INF + 1;i++){
        if(isprime(i))printf("%d," ,i);
        cnt++;
    }
    cout << cnt << endl;
 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
