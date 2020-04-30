/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-11 16:14:55
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
int n , p[maxn], son[maxn], a[maxn];
ll ans ;
int main()
{
    close;
    cin >> n;
    int dep = 1;
    a[1] = 1;
    map<int , int>mp;mp[1] = 1;
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        son[i]++;
        a[i] = a[p[i]]+1;
        mp[a[i]]++;
        dep = max(dep, a[i]);
    }
    for(int i = 1; i <= n; i++)ans += 1ll * son[i] * (son[i] - 1);
    for(int i = 1; i <= dep; i++){
        if(i >= 3)ans += mp[i] * mp[i-2];
    ]cout << 
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/