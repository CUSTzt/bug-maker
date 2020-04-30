#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
#define int long long 
int a[maxn];
int32_t main()
{
    close;
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