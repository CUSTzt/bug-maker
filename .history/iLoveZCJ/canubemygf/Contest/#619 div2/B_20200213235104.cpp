/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 23:48:21
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
int t , n , a[maxn], cz , num;
set<int >s;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        s.clear();
        int qi = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(qi == -1 && a[i] != -1)
        }
    }
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/