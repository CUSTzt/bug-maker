/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-11 15:13:37
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
vector<int > sz;
int main()
{
    cin >> s;
    int len = s.length();
    int jiahao = 0;
    for(int i = 0; i < len ; i++){
        if(s[i] == '+')jiahao++;
        else sz.emplace_back(s[i]);
    }
    jiahao++;
    sort(sz.begin(), sz.end());
    vector<int > jiashu[jiahao];
    vector<int > ans;
    int yu = len % (jiahao);
    for(int i = yu ; i <= jiahao; i++){
        jiashu[i].emplace_back(0);
    }
    for(int i = 0; i < len; i++){
        jiashu[i % jiahao].emplace_back((s[i] - '0'));
    }
    int tmp = 0;
    int jiwei = ceil(1.0*len/jiahao);
    for(int i = jiwei; i >= 0;i){

    }

}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/