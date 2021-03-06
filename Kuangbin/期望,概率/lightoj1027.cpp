 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年09月25日 星期三 20时54分24秒
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
int main(){
    int t ;
    cin >> t;
    for(int kase = 1; kase <= t;kase++){
        int n ;
        cin >>  n;
        int x;
        int neg=0 , pos=0 , posv=0, negv=0;
        for(int i = 0; i < n;i++){
            cin >> x;
            if(x > 0){
                pos++;
                posv+=x;
            }else {
                neg++;
                negv-=x;
            }
        }
        printf("Case %d: ",kase);
        if(pos == 0){
            cout << "inf" << endl;
            continue;
        }
        int aa = negv+posv;
        int bb = n - neg;
        int kk = __gcd(aa, bb);
        cout << (aa/kk) << "/" << (bb/kk) <<endl;
  
        
    }
    return 0;
}

/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
