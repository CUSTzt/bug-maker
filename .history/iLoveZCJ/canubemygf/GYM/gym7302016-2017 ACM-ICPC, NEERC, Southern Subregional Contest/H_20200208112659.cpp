/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-08 11:21:55
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
int a[110];
int n , m ;
string s[110];
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int fl = 0;
    int len = 0;
    vector<string > v;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        v.push_back(s[a[i]]);
        if(!len)len = s[a[i]].size();
        else {
            if(len != s[a[i]].size())fl = 1;
        }
    }
    if(fl)puts("No");
    else{
        string ANS = "";
        int size = v.size();
        for(int i = 0; i < size; i++）{
            
        }
    }

    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/