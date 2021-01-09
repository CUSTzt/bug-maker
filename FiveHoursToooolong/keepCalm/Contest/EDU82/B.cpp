#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int unsigned long long
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int32_t main()
{
    int t , n , g , b;
    cin >> t;
    while(t--){
        cin >> n >> g >> b;
        int nn = (n+1) / 2;
        if(g >= nn){
            cout << n << endl;
            continue;
        }
        int ans;
        int aa = nn / g;
        int bb = nn % g;
        if(bb == 0){
            ans = (g+b)*aa-b;
        }else ans = (g+b)*aa+bb;
        if(ans < n)ans = n;
        cout << ans << endl;
    }
 
}