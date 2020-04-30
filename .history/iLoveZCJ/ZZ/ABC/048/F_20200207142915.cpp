/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-07 14:24:52
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
ll bin(ll x , ll n , ll MOD){
    ll ret = MOD != 1;
    for(x %= MOD; n ; n >>= 1, x = x * x % MOD)
        if(n & 1)ret = ret * x % MOD;
    return ret;
}
int n , len , k , tot[maxn];
vector<int > v;
int main()
{
    cin >> n >> k;
    len = sqrt(n);
    for(int i = 2; i <= len; i++){
        if(n % i == 0){
            v.emplace_back(i);
            if(i != n / i)v.emplace_back(n / i);
        }
    }sort(v.begin(), v.end());
    int size  = v.size();
    ll ans = 0;
    for(int i = 0 ; i < size ; i++){
        tot[i] = bin(k , (v[i] + 1) / 2,)
    }
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/