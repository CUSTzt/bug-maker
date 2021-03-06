/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-09 22:35:49
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
//#define int long long 
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , a[maxn], b[maxn], c[32];
int32_t main()
{
    close;
    cin >> n;
    int wei = 0;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        for(int j = 0; j <= 31; j++){
            if(a[i] & (1 << j))c[j]++;
        }
    }
    for(int i = 0; i < 32; i++){
        if(c[i] == 1)wei = i;
    }
    for(int i = 0; i < n;i++){
        if((a[i] & (1 << wei) ))cout << a[i] << ' ';
    }
    for(int i = 0; i < n;i++){
        if((a[i] & (1 << wei) )== 0)cout << a[i] << ' ';
    }
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/