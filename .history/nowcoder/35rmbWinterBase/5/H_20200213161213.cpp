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
    /*int res = 25,tmp = 26;
    for(int i = 1; i <= 5;i++){
        tmp *= 26;
        res += tmp;
    }*/
    
    if(num > res)return true;
    else return false;
}
int32_t main()
{
    while(~scanf("%s %d", ch,&mod)){
        int len = 6;
        num = 0;
        for(int i = 0; i < len ; i++){
            num = (num * 26 + ch[i] - 'a');
           // cout << "num === " << num << endl;
        }
        num+=mod;
        if(check(num))puts("-1");
        else{
            vector<char> ANS;
            while(num){
                //cout << "nummmm == " << num << endl;
                int kp = num % 26;
                //cout << char(kp+'a') << endl;
                ANS.push_back('a'+kp);
                num-=kp;num/=26;
            }
            while(ANS.size() < 6)ANS.push_back('a');
            reverse(ANS.begin(),ANS.end());
            for(auto x : ANS)cout << x;
            cout << endl;
             
        }
    }
}