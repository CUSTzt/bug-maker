/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-28 14:21:42
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
int a[maxn];
int32_t main()
{
    close;
    int n , k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a , a+n);
    int ans = 0;
    for(int i = 0; i < n-k; i++){
        ans += a[i];
    }cout << ans << endl;
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/