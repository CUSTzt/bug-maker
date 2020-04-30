/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-08 12:09:07
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
//  质因数分解： 扫描2~√n  的数整除，并且记录个数  O(√n)
int p[maxn],c[maxn];
int m ;
void divide(int n){
    m = 0;
    int sqrtn = sqrt(n);
    for(int i = 2; i <= sqrtn; i++){
        if(n % i == 0){  //i是质数
            p[++m] = i;
            c[m] = 0;
            while(n % i == 0)n /= i,c[m]++; // 除掉所有的i
        }
    }
    if(n > 1)//n是质数
        p[++m] = n, c[m] = 1;
    /*for(int i = 1; i <= m; i++)
        cout << p[i] << '^' << c[i] <<endl;*/
}
int32_t main()
{
    int n;
    cin >> n;
    divide(n);
    if(n == 1){cout << 1 << " " << 0 << endl;exit(0);}
    int mi = *min_element(c+1, c+1+m), mx = *max_element(c+1, c+1+m);
    int cnt = 0;
    int l = 1ll;
    for(int i = 1; i <= m; i++){
        l *= p[i];
    }
    int tmp = 1;
    int r = 0;
    while(tmp < mx){
        tmp *= 2;
        r++;
    }
    if(tmp > mx || tmp > mi)r++;
    cout << l << " " << r << endl;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
