/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-11 13:10:28
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
    string s;
    cin >> s;
    stack<char> sk;
    int len = s.length();
    int flag = 1;
    for(int i = 0; i < len; i++){
        if(s[i] == '('||s[i] == '{'||s[i] == '['){
            sk.push(s[i]);
        }else {
            if(s[i] == ')' ){
                 if(sk.top()!='('){flag = 0;break;}
                else sk.pop();
            }else if(s[i] == ']'){
                if(sk.top()!='['){flag = 0;break;}
                else sk.pop();
            }else {
                if(sk.top()!='{'){flag = 0;break;}
                else sk.pop();
            }
        }
    }
    
    if(flag)cout << "YES\n";
    else cout << "NO\n";
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/