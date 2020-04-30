/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-11 15:37:47
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
string s;
int main()
{
    int jia = 0;
    cin >> s;int len = s.size();
    vector<int >num;
    for(int i = 0; i < len ; i++){
        if(s[i] == '+')jia++;
        else num.emplace_back(s[i] - '0');
    }jia++;sort(num.begin(),num.end());
    for(auto it : num)cout << it ;cout << endl;
    vector<int > zcj[jia];
    for(int i = 0; i < jia; i++)zcj[i].clear();
    int MO = num.size() % jia;
    if(MO)for(int i = MO;i < jia; i++){
        zcj[i].emplace_back(0);
    }
    for(int i = 0; i < num.size();i++){
        zcj[i % jia].emplace_back(num[i]);cout << "ss" <<endl;
    }
    int tmp = 0;
    int wei = ceil(1.0*num.size()/jia);
    vector<int > ans;
    ans.clear();
    for(int i = wei;i >= 0; i--){
        for(int j = 0; j < jia; j++){
            tmp+=zcj[j][i];
        }
        int tk = tmp % 10;
        
        tmp /= 10;
        ans.emplace_back(tk);
    }
    /*for(int i = 0; i < jia; i++){
        for(int k = 0; k < zcj[i].size(); k++){
            printf("zcj[%d][%d] === %d\n",i , k ,zcj[i][k] );
        }
    }*/
    while(tmp){
        int tk = tmp % 10;ans.emplace_back(tk);
        tmp /= 10;
    }
    int si = ans.size();
    for(int i = si-1; i >= 0; i++){
        cout << ans[i] ;
    }
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/