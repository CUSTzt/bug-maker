/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-09 22:09:50
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[maxn ], n , t;
int main()
{
    close;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n*2;i++){
            cin >> a[i];
        }
        sort(a, a+2*n);
        cout << a[n] - a[n-1] <<endl;
    }
 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/