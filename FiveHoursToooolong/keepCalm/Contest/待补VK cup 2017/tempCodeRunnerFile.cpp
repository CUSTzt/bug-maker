/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-10 16:04:20
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
int n  , a[maxn], b[maxn], c[maxn];
int32_t main()
{
    close;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tp;cin >> tp;
        int j = 0, tmp = 1;
        while(tmp < tp){
            j++, tmp <<= 1;
        }
        if((1 << j) == tmp){
            a[j]++;
        }else b[j-1] ++;
    }
    int i , j;
    for( i = a[0]; i > 0; i--){
        int k = i;
        for(j = 0; j <= 40; j++){
            k = min(k , a[j]);
            c[j] = k;
            //cout << "k ==== " << k << endl;
        }
        int s = 0;
        for(j = 40; j >= 0; j-- ){
            s += a[i] + b[j] - c[j];
            cout << "s === " << s << endl << "c["<<j<<"]=="<<c[j] <<endl;
            if(s > c[j])break;
        }
        if(j >= 0)break;
    }
    if(i == a[0]){
        puts("-1");exit(0);
    }
    i++;
    for( ; i <= a[0]; i++){
        cout << i << ' ';
    }cout << endl;
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/