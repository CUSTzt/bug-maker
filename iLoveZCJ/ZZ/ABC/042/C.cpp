/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-27 11:19:53
# @Description: You build it. You run it
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
int a[maxn],b[maxn];
int zcj(char c){
    return c - '0';
}
int main()
{
    int ans = 100000;
    int n , k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> a[i];
        b[a[i]] = 1;
    }
    for(int i = 100000; i >= n ; i--){
        string s = to_string(i);
        int len = s.length();
        int f = 0;
        for(int i = 0; i < len ; i++){
            if(b[zcj(s[i])]){
                f=1;break;
            }
        }
        if(!f){
            ans = i;
        }
    }
    cout << ans << endl;
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/