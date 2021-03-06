//https://www.cnblogs.com/linzhuohang/p/11519936.html
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
#define int long long 
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
int32_t main()
{
    cin >> n >> k;
    len = sqrt(n);
    for(int i = 1; i <= len; i++){
        if(n % i == 0){  //获取所有可能的循环节长度
            v.emplace_back(i);
            if(i != n / i)v.emplace_back(n / i);
        }
    }sort(v.begin(), v.end());
    int size  = v.size();
    ll ans = 0;
    for(int i = 0 ; i < size ; i++){
        tot[i] = bin(k , (v[i] + 1) / 2, mod); ;//循环节长度为v[i]时循环节的数量。因为是回文串，所以只需要知道前面半截即可确定出整个回文串，下面也是同理
        for(int j = 0 ; j < i ; j++){
            if(v[i] % v[j] == 0){
                tot[i] = (tot[i] + mod - tot[j]) % mod; //去除【长度为v[i]的循环节】内部含有循环节的情况
            }
        }
        if(v[i] & 1){ans += tot[i] * v[i]; ans %= mod;}
        else {ans += tot[i] * (v[i] / 2) ; ans %= mod;}
    }cout << ans << endl;
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/