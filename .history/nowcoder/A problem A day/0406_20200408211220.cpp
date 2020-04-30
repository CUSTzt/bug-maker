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
    ll le = x * 10, ri = 
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