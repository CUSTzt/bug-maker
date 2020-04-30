/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 13:18:19
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long 
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , cnt ,a[maxn], b[maxn], ans, vis[maxn];
vector<int >v[maxn];
ll work(){

}
int32_t main()
{
    close;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int j = 1; j <= j; j++)cin >> b[j];
    ans += a[1];
    for(int i = 2; i <= n; i++){
        if(vis[i])continue;
        ll x = i;
        cnt ++;

    }

    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/