/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-17 14:28:07
# @Description: You build it. You run it 
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
double f[500];
int a[maxn];
void work(int n){
	for(int i = 1; i <= n ;i++){
		a[i] = i;
	}
	double ans = -1;
	do{
		for(int  i = 1; i <= n;i++){
			for(int j = i; j<=n;j++){
				double tmp = 0;
				for(int k = i ; k <= j; k++){
					tmp += a[i];
				}
				double pp = (1.0*tmp ) / (j-i+1);
				if(pp >= ans){
					ans = pp;
					for(int kkk = 1; kkk <= n; kkk++){
						cout << a[kkk ] << " ";
					}
					cout << endl;
				}	
			}
		}

	}while(next_permutation(a+1, a+1+n));
}
int main(){
	for(int i = 5; i <= 5;i++){
		cout << " ----- " << endl;
		work(i);
		cout <<  "----------------" << endl;
	}
 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
