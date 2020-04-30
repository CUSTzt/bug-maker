/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-27 16:37:37
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int32_t main()
{
    int h , w;
    cin >> h >> w;
    int l = 0, r = 0;
    for(l = 0; ; l++){
        if((1 << l) > h || (1 << l) > (5*w)/4){
            l--;break;
        }
    }
    for(r = 0; ; r++){
        if((1 << r) > w || (1 << r) > (5*h)/4){
            r--;break;
        }
    }
    int hh = 1 << l,ww = 1 << r;
    int ans_h = min(h , 5*ww / 4);
    int ans_w = min(w , 5*hh / 4);
    if(hh * ans_w > ww*ans_h){
        cout << hh << " " << ans_w << endl;
        return 0;
    }else if(hh * ans_w < ww*ans_h){
        cout << ans_h << " " << ww <<endl;
    }else cout << max(hh , ans_h) << " " << min(ww , ans_w) << endl;
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/