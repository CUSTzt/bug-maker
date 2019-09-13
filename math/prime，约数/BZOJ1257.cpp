/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-16 19:49:35
 * @Description: You build it, You run it.  
 ***********************************************/
#include <bits/stdc++.h>
#define int long long
const int maxn = 1e6+10;
#define eps 1e-8
using namespace std;
main()
{
	int n , k, ans ;
	cin >> n >> k;
	ans = n * k;
	for(int x = 1, gx ;x <= n; x = gx + 1 ){
		gx = k/x ? min(k/(k/x) , n ) : n;
		ans -= (k / x) * (x + gx) * (gx - x +1) / 2;
	}   
	cout <<ans <<endl ;
	return 0;
} 

/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
/*
for(long long l=1,r=0;l<=n;l=r+1)
    {
        if(k/l)r=min(n,k/(k/l));
        else r=n;
        ans-=(k/l)*(r-l+1)*(l+r)>>1;
    }
 */
//分块的思想
//
/*
LL ans=(n>k)?k*(n-k):0,i=1;
    for(;i<=min(n,k);){
        LL j=min(k/(k/i),n);
        ans+=k*(j-i+1)-(k/i)*(i+j)*(j-i+1)/2;
        i=j+1;
    }
    printf("%lld",ans);
 */