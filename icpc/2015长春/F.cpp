 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年12月30日 星期一 16时21分19秒
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
int a[maxn];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p = 0, pp = 0;
        for(int i = 0; i < n;i++){
            scanf("%d", &a[i]);
            if(i >= 1){
                if(a[i] > a[i-1])p++;
            }
        }
            if(p <= 1)puts("YES");
            else puts("NO"); 
    }
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
