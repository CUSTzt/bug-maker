/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 22:25:46
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
    string a, b , c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int len = a.size();
        int fl = 1;
        for(int i = 0; i < len ; i++){
            if(c[i] != b[i] && c[i]!= a[i])fl = 0;
            
        }
        if(fl)puts("YES");else puts("NO");
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/