/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 22:25:54
# @Description: Think twice. Code once. 
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
int a[maxn], n,m , ans , x , y , xx , yy , sp;
int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        cin >> n >> m;
        ans=n*(n+1)/2;
        n-=m;
        m++;
        LL x=n/m+1;
        LL y=n/m;
        LL xx=n%m;
        LL yy=m-xx;
        LL as=0;
        sp=xx*(x*(x+1)/2)+yy*(y*(y+1)/2);
        printf("%lld\n",ans-as);
 
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/