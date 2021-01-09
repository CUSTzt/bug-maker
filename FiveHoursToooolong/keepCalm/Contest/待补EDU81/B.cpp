/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-30 10:15:28
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
int main()
{
    int t;
    cin >> t;
    int n , x;
    string s;
    while(t--){ 
        cin >> n >> x;
        cin >> s;
        int a[n] = {0};
        for(int i = 0; i < n; i++){
            a[i] = (i? a[i-1] : 0) + (s[i] == '0' ? 1 : -1);
        }
        if(a[n-1] == 0){
            //int l = 0;
            int i;
            for( i = 0; i < n;i++){
                //l = i;
                if(a[i] == x)break;
            }
            cout << ((i < n) ?"-1" : "0") <<endl;
            continue;
        }
        int ans;
        if(x == 0)ans = 1;
        else ans = 0;
        for(int i = 0; i < n; i++){
            if((x - a[i]) % a[n-1] == 0 && (x-a[i])/a[n-1]>=0)ans++;
        }cout << ans << endl;
    }
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/