/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 14:27:42
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
    int t ;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int xo = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            xo |= a[i]; 
        }
        if(*max_element(a , a+n) == 1 ){
            if(n & 1)puts("Brother");else puts("John");
        }
        else {
            puts(xo ? "John" : "Brother")
        }
    }
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/