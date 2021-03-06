/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-11 14:49:10
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
const int mod = 998244353;
ll bin(ll x , ll n , ll MOD){
    ll ret = MOD != 1;
    for(x %= MOD; n ; n >>= 1, x = x * x % MOD)
        if(n & 1)ret = ret * x % MOD;
    return ret;
}
int n , k , a[maxn], b[maxn], l , r;
int work(int ll){
    int ret = 1; 
    for(int i = l ; i < l+k; i++){
        ret = ret * a[i] % mod;
    }return ret;
}
int main()
{
    close;
    int cnt = 0;
    cin >> n >> k;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!a[i])b[++cnt] = i;
    }
    l = 1, r = k;
    int m = 1;
    if(b[m] < r){
        l = b[m] + 1;
        r = l+k-1;
        m++;
    }
    while(r <= n+1){
        int wo = work(l);
        mx = max(mx , wo);
        int kp = wo;
        for(int i = l; i < b[m];i++){
            kp = kp * bin(a[i], mod - 2, mod) % mod * a[r] % mod;
            mx = max(mx , kp);
            r++;
        }
        m++;
        if(m > cnt){
            for(int i = l; i <= n;i++){
                kp = kp * bin(a[i], mod - 2, mod) % mod * a[r] % mod;
                mx = max(mx , kp);
                r++;
            }
        }
    }
    cout << mx << endl;    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/