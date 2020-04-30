/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-14 14:59:11
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
using LL = long long;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
bool isprime(int x){
    int m = sqrt(x + 0.5);
    for(int i = 2; i <= m; i++){
        if(x % i == 0)return false;
    }
    return true;
}
int n , mod;
std::vector<int > v;
void pre(int x){
    int m = sqrt(x + 0.5);
    for(int i = 2; i <= m;i++){
        if(x % i == 0){
            v.push_back(x % i);
            if(x / i != i){
                v.push_back(x / i);
            }
        }
    }
}
int check(int x){
    if(x < 0)x += mod;
    return x;
}
int cal(int x){
    return (x*(x+1)/2-1+mod)%mod;
}
int32_t main()
{
    cin >> n >> mod;
    int inv = get_inv(6, mod);
    //cout << inv << endl;
    int ans = ((n*(n+1)%mod*(2*n+1)%mod*inv)%mod+(n-1))%mod;
    if(isprime(n)){
        cout << ans << endl;
        return 0;
    }
    pre();
    int size = v.size();
    for(int i = 0; i < size; i++){
        int tp = v[i];
        int shuliang = cal(v[i]);
        int si = (v[i] - 1 ) * shuliang % mod;
        ans = check(ans);
    }
    cout << ans << endl;
    return 0;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
