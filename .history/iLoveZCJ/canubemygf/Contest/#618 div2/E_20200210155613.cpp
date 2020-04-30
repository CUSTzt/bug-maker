/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-10 09:50:58
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
int n , a[maxn], sum[maxn], stk[maxn], top;
double K(int x, int y){
    return double(sum[y] - sum[x] ) / (y-x);
}
int main()
{
    close;
    cin >> n ;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        while(top && K(stk[top-1], i) < K(stk[top-1], stk[top]))top--;
        stk[++top] = i;
    }
    for(int  i = 1; i <= top; i++){
        double ans = K(stk[i-1], stk[i]);
        for(int j = 1; j <= stk[i] - stk[i-1]; j++){
            printf("%.10f",ans )
        }
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/