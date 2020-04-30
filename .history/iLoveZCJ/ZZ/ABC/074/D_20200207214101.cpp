/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-07 21:33:43
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , a[maxn][maxn] , b[maxn][maxn];
ll ans ;
void check(){
    for(int i = 1; i <= n; i++)
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int flag = 0;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            for(int k = 1; k <= n ; k++){
                if(i != j && i != k && j != k && a[i][j] > a[i][k] + a[k][j]){
                    flag = 1;
                }
                 if(i != j && i != k && j != k && a[i][j] == a[i][k] + a[k][j]){
                    b[i][j] = 1;  //i到j这条边不要
                }
            }
        }
    }
    if(flag)puts("1");
    else {

    }
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/