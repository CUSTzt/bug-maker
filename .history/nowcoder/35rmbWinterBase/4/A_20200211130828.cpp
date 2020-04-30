/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-11 13:00:56
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
int a[maxn];
int main()
{
    a[1] = 1;a[2] =2;
    for(int i = 3; i <= 100;i++){
        a[i] = a[i-1]+a[i];
    }
    for(int i = 1; i <= 80; i++){
        cout << a[i] << endl;
    }
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 0){cout << 1 << endl;continue;}
        else cout << a[n]+a[n+1] <<endl;
    }
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/