/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-07 10:51:59
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
int n, a[maxn] , x;
ll ans;
int main()
{
    close;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        int tmp = a[i] + a[i+1] - x;
        if(tmp < 0)tmp = 0;
        ans += tmp;
        a[i + 1] -= tmp;
        if(a[i + 1] < 0) a[i + 1] = 0;
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