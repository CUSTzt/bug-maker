/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-21 20:46:12
 * @Description: You build it, You run it.
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e6+10;
using namespace std;
int a[maxn] ,c[maxn] ,ans ,max_val ,n ,l[maxn], r[maxn];
int ask(int x){
	int ans = 0;
	for( ; x; x -= lowbit(x))ans += c[x];
		return ans;
}
void add(int x,int y){
	for(; x <= n; x += lowbit(x))c[x] += y ;
}
void res1(){
	for(int i = n; i ; i--){
		r[i] = ask(max_val) - ask(a[i]);
		add(a[i], 1);
	}
	memset(c, 0 , sizeof(c));
	for(int i = 1; i <= n;i++ ){
		l[i] = ask(max_val) - ask(a[i]);
		add(a[i] , 1);
	}
}
void res2(){
	memset(c, 0 , sizeof(c));
	for(int i = n; i ; i--){
		r[i] = ask(a[i] - 1);
		add(a[i] , 1);
	}
	memset(c , 0 ,sizeof(c));
	for(int i = 1; i <= n ;i++){
		l[i] = ask(a[i] - 1);
		add(a[i], 1);
	}
}
int get_ans(){
	int ans = 0;
	for(int i  = 1; i <= n;i++){
		ans += l[i] * r[i];
	}
	return ans;

}
main()
{
	cin>>n;
	for(int i = 1; i <= n;i++){
		cin>>a[i];
	}
	max_val = *max_element(a+1, a+n+1);
	res1();
	cout << get_ans()<<' ';
	res2();
	cout << get_ans()<<endl;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
