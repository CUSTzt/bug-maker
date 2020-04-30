/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-10 09:35:35
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
struct edge{
    double k ;
    int len;
}e[maxn];
int n, x[maxn], y[maxn];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(i){
            e[i-1].k = fabs(1.0*y[i] - y[i-1]) / fabs(1.0*x[i]- x[i-1]);
            e[i-1].len = (y[i] - y[i-1]) * (y[i] - y[i-1]) + (x[i] - x[i-1]) * (x[i] - x[i-1]);
        }
    }
    e[n-1].k =fabs(1.0*y[n-1] - y[0]) / fabs(1.0*x[n-1]- x[0]);
    e[n-1].len = (y[n-1] - y[0]) * (y[n-1] - y[0]) + (x[n-1] - x[0]) * (x[n-1] - x[0]);
    if(n & 1){
        puts("NO");exit(0);
    }
    for(int i = 0; i < n/2; i++){
        if(fabs(e[i].k - e[i+n/2].k) > eps || e[i].len != e[i+n/2].len){puts("NO")}
    }
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/