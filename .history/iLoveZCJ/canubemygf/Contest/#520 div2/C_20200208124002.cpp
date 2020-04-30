/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-08 12:33:38
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
    string cod = "CODEFORCES";
    string s;
    cin >> s;
    int len = s.length();
    int i = 0, j = 0;
    while(s[i] == cod[i] ){
        i++;
    }
    while(s[len - 1 - j] == cod[9 - j] ){
        j++;
        if(j > 10)break;
    }
    if(i + j >= 10)puts("YES");else 
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/