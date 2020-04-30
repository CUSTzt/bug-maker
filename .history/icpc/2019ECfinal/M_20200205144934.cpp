/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 13:18:19
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long 
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , cnt , a[maxn], use[maxn],b[maxn],ans, vis[maxn];
vector<int >v[maxn];
ll work(vector<int >& v){
    int n = v.size();
    int res = 0;
    for(int i = 0; i < (1 << n); i++){
        for(auto x : v)use[x] = 0;
        int tmp = 0;
        for(int j = 0; j < n;j++){
            if(i & (1 << j)){
                tmp += a[v[j]];
                int tp = v[j]*v[j];
                while(tp <= n){
                    use[tp]++;x*=
                }
            }
        }
    }
}
int32_t main()
{
    close;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int j = 1; j <= j; j++)cin >> b[j];
    ans += a[1];
    for(int i = 2; i <= n; i++){
        if(vis[i])continue;
        ll x = i;
        cnt ++;
        while(x <= n){
            v[cnt].emplace_back(x);
            vis[x] = 1;
            x *= i;
        }
    }
    for(int i = 1; i <= cnt ;i++){
        ans += work(v[i]);
    }cout << ans << endl;
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/