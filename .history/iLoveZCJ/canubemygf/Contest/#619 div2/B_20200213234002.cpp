/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 22:45:17
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int t , si,n ,a[maxn],b[maxn];
std::vector<int > v;
int cz, numm;
void check(int x){
    int qi = v[0];
    for(int i = 1; i < si;i++){
        if(v[i] == -1){
            v[i] = x;
        }
        if(abs(v[i] - qi) > cz){
            numm = x;
            cz = abs(v[i] - qi);
        }
        //cz = max(cz, abs(v[i] - qi));
        qi = v[i];
    }
}
int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i <= n+10;i++){
            b[i] = 0;
        }
        int cnt = 0;
        v.clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i];if(a[i]!=-1)b[++cnt] = a[i];
            if(i == 1)v.emplace_back(a[i]);
            else {
                if(a[i] == -1 && v.back() == -1)continue;
                else v.emplace_back(a[i]);
            }
        }
        int mx = *max_element(a+1,a+1+n),mn = *min_element(b+1,b+1+cnt);
        numm = 
        si = v.size();
        cz = -1;
        set<int>st;
        for(int i = 1; i < si;i++){
            if(a[i] == -1)continue;
            if(a[i-1]!=-1)cz=max(abs(a[i]-a[i-1]),cz);
            if(a[i-1] == -1 && i >= 2){
                st.insert((a[i]+a[i-1])/2);
                st.insert((a[i]+a[i-1])/2+1);
                st.insert((a[i]+a[i-1])/2-1);
            }
        }
        for(auto )

    }
 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/