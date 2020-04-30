/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-28 15:06:55
# @Description: You build it. You run it
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
int d , n , a ,c[maxn];
struct node{
    int x, h;
}mon[maxn];
int cmp(node a , node b){
    return a.x < b.x;
}
int32_t main()
{
    close;
    cin >> n >> d >> a;   
    for(int i = 0; i < n; i++){
        cin >> mon[i].x >> mon[i].h;
    }
    sort(mon , mon + n , cmp);
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && mon[j].x <= mon[i].x + 2*d)++j;
        int tmp = max((mon[i].h - c[i]*a + a - 1)/a, 0ll);
        ans += tmp;
        c[i] += tmp;
        c[j] -= tmp;
        c[i+1] += c[i];
    }cout << ans << endl;
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/