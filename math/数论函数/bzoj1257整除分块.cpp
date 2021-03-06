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
ll n , k , ans;
/*void work(int n , int k){
    ans = n * k;
    for(int x = 1, gx ; x <= n; x = gx + 1){
        gx = k / x ? min(k / (k / x), n) : n;
        ans -=(k / x) * (x + gx) * (gx - x + 1) / 2;
    }
}*/
void work(int n , int k){
    ans = n*k;
    for(int l = 1, r; l <= n; l = r+1){
        if(k / l != 0) r = min(k/(k/l),n); 
        else r = n;
        //cout << "l === " << l << " r==== " << r << endl;
        ans -= (k / l) * (l+r) * (r-l+1) / 2;
    }
}
int32_t main()
{   
    cin >> n >> k;
    work(n , k);
    cout << ans << endl;
    //system("pause");
}