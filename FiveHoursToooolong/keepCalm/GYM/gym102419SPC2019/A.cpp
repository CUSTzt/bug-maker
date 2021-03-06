/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-12 19:14:48
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
int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if(s > t){
        if( n > 2){
            cout << "YES\n";
            cout << n-1 << ' ' << n <<endl;return 0;
        }else{
            swap(s[0],s[1]);swap(t[0],t[1]);
            if(s > t){
                cout << "YES\n1 2\n";
            }else cout << "NO\n";
            return 0;
        }
    }
    //int l = -1, r = -1;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] > t[i]){
            cout << "YES\n";
            cout << 1 << ' ' << i+1 << endl;return 0;
        }
    }cout << "NO\n";
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/