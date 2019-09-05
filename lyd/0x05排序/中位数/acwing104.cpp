/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-19 21:24:50
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define int long long
const int maxn = 1e6+10;
#define eps 1e-8
using namespace std;
//int a[maxn];
main()
{
	int n;
	cin>>n;
	int a[n+1]={0};
	for(int i =1; i <= n;i++){
		cin>>a[i];
	}
	int mid_num = 0;
	int ans = 0;
	sort(a+1,a+1+n);
	//if(n&1){
		mid_num = a[(n+1)/2];
		for(int x:a){
			ans += abs(x - mid_num);
		}
	//}
	cout<<ans-mid_num<<endl;


}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
