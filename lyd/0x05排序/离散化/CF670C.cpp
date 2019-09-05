/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-19 20:42:07
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define int long long
const int maxn = 1e6+10;
#define eps 1e-8
using namespace std;
int a[maxn],b[maxn];
map <int ,int > mapp;

main()
{
	int p = 0,q = 0,r =1;
	int n; 
	int m;
	cin>>n;
	int x;
	for(int i= 0; i < n;i++){
		cin>>x;
		mapp[x]++;
	}
	cin>>m;
	for(int i = 0; i < m;i++){
		cin>>a[i];
	}
	for(int i = 0; i < m;i++){
		cin>>b[i];
	}
	for(int i = 0; i < m;i++){
		if(mapp[a[i]]>q||(mapp[a[i]]==q&&mapp[b[i]]>p)){
			q = mapp[a[i]];
			p = mapp[b[i]];
			r = i+1;
		}
	}
	cout << r<<endl;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
