/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-12 22:35:03
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
int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        int mx = maxn;
        int cnt = 0;
        cin >> s;
        int len = s.length();int l = 0 , r = len;
        for(int i = 0;i < len; i++){
            if(s[i] == '1'){l = i; break;}
        }
        for(int i = len-1; i>= 0;i--){
            if(s[i] == '1')
        }
    }
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/