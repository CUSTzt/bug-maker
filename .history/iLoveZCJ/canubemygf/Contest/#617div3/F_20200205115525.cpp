/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-05 10:52:32
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 1e6;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , m ;
vector<pair<int , int > >edges;
vector<vector<int> >e;
vector<int >dep, par, f;
vector<tuple<int , int , int > > passengers;
void dfs(int u){
    for(int v : e[u]){
        
    }
}
int main()
{
    
    
    //system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/