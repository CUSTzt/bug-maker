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
    if(s.length() != 16)return ;
    /*if(s[15] == '1' && s[13] == '9' && s[11] == '2' && s[9] == '6' && s[7] == '0' && s[1] == '7' && s[5] == '8'){
        cout << s << endl;fl = 1;
    }*/
    if(s[1] == '7' && s[3] == '1' && s[5] == '8' && s[7] == '0' && s[9] == '6'&& s[11]== '2' && s[13] == '9' && s[15] == '1'){
        cout << s << endl;fl = 1;
    }
}
int32_t main()
{
    /*ll i;
    for( i = 3e7; i <= 4e8;i++){
        check(i*i);if(fl)break;
    }*/
      
    string s = "2761289046024961";
    cout << s << endl;
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/