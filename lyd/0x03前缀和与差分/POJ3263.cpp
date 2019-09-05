/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-19 10:57:36
 * @Description: You build it, You run it.  
 ***********************************************/
//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <cassert>
#include <map>
#define ll long long
const int maxn = 1e6+10;
#define eps 1e-8
#define mp make_pair
using namespace std;
typedef pair<int ,int > P;
map <P , bool>existed;
int c[maxn],d[maxn];
int n , m ,h ,p;
int main()
{
	cin>>n>>p>>h>>m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		if(a > b)swap( a , b);
		if(existed[mp(a,b)])continue;
		d[a + 1]--,d[b]++;
		existed[mp(a,b)] = true;
	}
	for(int i = 1; i <= n;i++){
		c[i] = c[i-1] +d[i];
		cout<<h+c[i]<<endl;
	}
	return 0;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
