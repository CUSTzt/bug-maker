/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-15 11:35:57
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 1e5;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int32_t main()
{
    int n , d, t;
    cin >> t;
    while(t--){
        cin >> n >>d;
        int fl = 0;
        for(int i = 0; i <= maxn; i++){
            if(i + ceil((1.0*d) / (i+1)) == n){
                fl = 1;
                break;
            }
        }
        cout << (fl ? "YES\n" : "NO\n");
    }
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
