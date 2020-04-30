/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 13:04:58
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
#define int long long 
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
struct node{
    int x, y ;
}a[maxn];
int n;
int32_t main()
{
    cin >> n;
    int sumx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        sumx += a[i].x;
    }
    int xx = sumx / n ;
    double ans = 1.0*linf;
    for(int kx = xx - 100; kx <= xx + 100;kx++){
        int k = -linf;
        for(int i = 0; i < n; i++){
            k = max(k , a[i].y*a[i].y+(a[i].x-kx)*(a[i].x-kx));
        }ans = min(ans , sqrt(ans))
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/