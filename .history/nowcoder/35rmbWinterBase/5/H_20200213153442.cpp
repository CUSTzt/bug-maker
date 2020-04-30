/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 15:29:16
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
char ch[6];
int mod, num;
bool check(int num){
    int res = 1,tmp = 1;
    for(int i = 1; i <= 6;i++){
        tmp *= 26;
        res += tmp; 
    }
    if(num >= res)return true;
    else return false;
}
int32_t main()
{
    scanf("%s", ch);
    cin >> mod;
    int len = 6;
    for(int i = len-1; i>=0 ; i--){
        num = (num * 26 + ch[i] - 'a');
    }
    num+=mod;

}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/