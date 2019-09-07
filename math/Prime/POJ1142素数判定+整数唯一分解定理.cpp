/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-16 10:34:29
 * @Description: You build it, You run it.
 ***********************************************/
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define ll long long
#define int long long
#define eps 1e-8
using namespace std;
const int maxn = 1e6+10;
const int MAX_L = 1e6+10;
const int MAX_SQRT_B = 1e6 +10;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];
const int linf = 0x3f3f3f3f3f3f3f3f;
int p[maxn];
//注意a==1 的情况   要减去1
//对区间【a，b）内的整数执行筛法  is_prime[i-a] = true;   <=>i 是 素数
int cnt;
void segement_sieve(ll a, ll b){
	cnt  = 0;
	memset(is_prime, false ,sizeof(is_prime));
	memset(is_prime_small,false ,sizeof (is_prime_small));
	for(int i = 0;(ll)i * i < b; i++)is_prime_small[i] = true;
	for(int i = 0; i <= b - a; i++)is_prime[i] = true;

	for(int i = 2; (ll)i * i < b; i++){
		if(is_prime_small[i]){
			for(int j = 2 * i;(ll )j * j < b;j+= i )is_prime_small[j] = false; //筛【2，√b）
			for(int j = max(2LL, (a+i-1)/i) * i ; j <= b; j += i)is_prime[j-a] = false;//筛【a，b）
		}
	}
	int MIN = linf, MAX = 0,minn = 0, maxx = 0 ;
	for(int i = a; i <= b; i++){
		if(is_prime[i-a] ){
			cnt++;
			p[cnt] = i;}
			if(cnt >= 2){
				if(MAX < p[cnt] - p[cnt - 1])
					maxx = cnt -1;
				MAX = (MAX > (p[cnt] - p[cnt - 1]) ? MAX : (p[cnt] - p[cnt - 1]));
				if(MIN > p[cnt] - p[cnt - 1])
					minn = cnt -1;
				MIN = (MIN < (p[cnt] - p[cnt - 1]) ? MIN : (p[cnt] - p[cnt - 1]));
			}
	}
	if (cnt < 2) cout <<"There are no adjacent primes.\n";
	else {
		//for(int i = 1; i <= cnt ; i++)
		//	cout << p[i]<<" ";
		//cout <<endl;
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n",p[minn] , p[minn+1] , p[maxx] , p[maxx+1]);
	}
}
 main()
{
	int a, b;
	while(cin>>a>>b){
		if(a == 1) a = 2;
		if(a > b )swap(a , b);
		segement_sieve(a , b);
	}
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
