/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-08 11:54:57
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , a[maxn], ans;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 0 << endl;
        exit(0);
    }
    a[0] = 0;
    a[n+1] = 1001;
    int tmp = 0;
    for(int i = 1 ; i <= n+1 ; i++){
        if(a[i] - a[i-1] == 1 && a[i+1] - a[i] == 1){
            tmp++;
        }else {
            ans = max(ans , tmp );
            tmp = 0;
        }
    }cout << ans << endl;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/