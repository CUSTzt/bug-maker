/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 10:01:50
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int main()
{
    int t , n , g ,  b;
    cin >> t;
    while(t--){
        cin >> n >> g >> b;
        int tot = g + b;
        int ans = 0;
        int nn = (n + 1) / 2;
        if(g >= n){
            cout << nn << endl;
        }else {
            int ll = 
        }
    }
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/