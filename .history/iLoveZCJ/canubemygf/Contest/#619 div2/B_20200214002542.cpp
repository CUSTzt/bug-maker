/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-14 00:16:48
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
#define int long long 
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int mxx, a[maxn], l , r , ll , rr , mid ;
int work(int x){
    mxx = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == -1 && a[i+1] == -1){
            mxx = max(mxx, 0ll);
            continue;
        }
        if(a[i ] == -1){
            mxx = (mxx, abs(x - a[i+1]));
            continue;
        }
        if(a[i+1] == -1){
            mxx = max(mxx, abs(a[i] - a[i+1]));
            continue;
        }
        mxx = max(mxx, abs(a[i] - a[i+1]));
    }return mxx;
}
int32_t main()
{
    l = 0;
    r = 1e9;
    while(r - l > 10){
        ll = l +(r-l+1)/3;
        rr = l +2*(r-l+1)/3;
        if(work(ll) > work(rr))l=ll;
        else r = rr;
    }
    int kpt = -1, ljk = -1, zcj ;
    for(int i = max(l - 4,0ll ); i <= min(r + 4,(ll)(1e9));i++){
        if(kpt == -1){
            ljk = i;
            kpt = work(i);
        }else 
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/