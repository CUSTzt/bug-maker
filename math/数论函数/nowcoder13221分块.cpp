// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
ll l, r;
ll slove(ll n , ll x){
    ll ans = n / x;
    ll le = x * 10, ri = min(n , x*10+9);
    for(; le <= n; le *= 10, ri = ri*10+9){
        ll k = min(n , ri);
        for(ll l = le , r; l <= k; l = r+1){
            r = min(n/(n/l),k);
            ans += n/l * (r-l+1);
        }
    }return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    l--;
    for (int i = 1; i <= 9; i++) {
        cout << slove(r, i) - slove(l, i) << endl;
    }
    return 0;
}