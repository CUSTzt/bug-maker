/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 13:14:29
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
ll mod = 1e9+7;int a[maxn];
int main()
{
    int n , m;
    int flag = 0;
    int tmp;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 8)tmp = a[i];
    }sort(a , a+n);
    //for(int i = 0; i < n;i++)cout << a[i];
    int kp = ceil(0.8*m);
    if(tmp >= kp)flag = 1;
    if(tmp >= a[n-3])flag = 1;
    if(flag)puts("Yes");else puts("No");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/