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
//ll mod = 1e9+7;
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
    while(~scanf("%s %d", ch,&mod)){
        int len = 6;
        num = 0;
        for(int i = len-1; i>=0 ; i--){
            num = (num * 26 + ch[i] - 'a');
        }
        num+=mod;
        cout << "num === " << num << endl;
        if(check(num))puts("-1");
        else{
            vector<char> ANS;
            while(num){
                int kp = num % 26;
                ANS.push_back('a'+kp);
                num-=kp;num%=26;
            }
            reverse(ANS.begin(),ANS.end());
            for(auto x : ANS)cout << x;
            cout << endl;
            
        }
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/