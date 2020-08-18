// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100, INF = 1e18;
int a[N], b[N], n;
void up() {
    cin >> n;
    int mxa = INF, mxb = INF;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mxa = min(mxa, a[i]);
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        mxb = min(mxb, b[i]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans+=max(a[i]-mxa, b[i]-mxb);
    }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}