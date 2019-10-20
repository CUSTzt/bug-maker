 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月08日 星期二 19时23分02秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
#include<bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[maxn], b[maxn] ,n;
double ansxor, ansand ,ansor;
void solve(int k ){
    int last[2] = {0,0}, c1 = 0, c2 = 0;
    for(int i = 1; i <= n; i++){
        b[i] = ((a[i] >> k) & 1);
        if(b[i]){
            ansxor += (1 << k)*1.0/n/n;
            ansand += (1 << k)*1.0/n/n;
            ansor  += (1 << k)*1.0/n/n;
        }
    }
    for(int i =1 ; i <= n;i++){
        if(b[i] == 0){
            ansor += (1 << k)*2.0/n/n*last[1];
        }else {
            ansand += (1 << k)*2.0/n/n*(i-1-last[0]);
            ansor += (1 << k)*2.0/n/n*(i-1);
        }
        ansxor += (1 << k)*2.0/n/n*(b[i]?c1:c2);
        c1++;
        if(b[i]) swap(c1,c2);
        last[b[i]] = i;
    }
}
int main(){
    cin >> n;
    for(int i =1; i <= n;i++)scanf("%d",&a[i]);
    for(int i = 0; i < 31;i++)solve(i);
    printf("%.3f %.3f %.3f\n", ansxor, ansand, ansor);
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
