#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100, mod=1e9+7;
#define int long long 
using LL=long long;
int a[maxn];
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        ans += n*a[i]%mod*a[i]%mod;
        ans%=mod;
    }
    // cout << sum << endl;
    ans -= bin(sum,2,mod);
    add(ans,mod);
    cout << ans << endl;
    
}