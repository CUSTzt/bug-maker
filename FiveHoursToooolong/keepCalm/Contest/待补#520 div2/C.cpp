/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-09 19:15:36
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
int n , a[maxn ], b[maxn];

int main()
{
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    int cnt = 0;
    for(int i = 1; i <= 110; i++){
        if(b[i]){
            for(int j = i; j <= 110; j += i){
                b[j] = 0;
            }cnt++;
        }
    }cout << cnt << endl;
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/