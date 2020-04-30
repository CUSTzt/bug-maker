/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-28 14:43:49
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int32_t main()
{
    int h;
    cin >> h;
    int ans = 0;
    int tmp = 1;
    while(h){
        h /= 2;
        ans += tmp;
        tmp *= 2;
    }
    cout << ans << endl;
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/