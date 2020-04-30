/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-11 18:08:26
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
int fl ;
void check(ll a){
    string s = to_string(a);
    if(s[0] == '15' && s[] == '2' && s[10] == '8' && s[8] == '0' && s[14] == '7'){
        cout << s << endl;fl = 1;
    }
}
int32_t main()
{
    for(ll i = 1e8; i <= 1e8;i++){
        check(i*i);if(fl)break;
    }
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/