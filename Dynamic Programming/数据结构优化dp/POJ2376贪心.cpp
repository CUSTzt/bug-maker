/*************************************
 * Author : miniLCT
 * More : You build it. You run it
 ************************************/
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#define ll long long
#define INF 0x3f3f3f3f 
#define lowbit(x) (x)&(-x)
#define FOR(i,f_start,f_end) for(int i=f_start;i<=f_end;++i) 
#define MT(x,i) memset(x,i,sizeof(x))
#define close std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000000009;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double E = exp(1);
const double EPS=1e-8;
const int maxn = 1e6+10;
struct Node{
	int left , right ;
}cow[maxn];
bool cmp(Node a, Node b){
	if(a.left != b.left)return a.left < b.left;
	else return a.left > b.left;
}
int n , t;

int main()
{
	cin >> n >>t;
	for(int i = 0; i < n ;i++){
		cin>>cow[i].left>>cow[i].right;
	}
	sort(cow , cow+n,cmp);
	int local = 0, ans = 0, p = -1;
	for(int i = 0; i < n ;i++){
		if(cow[i].left > local+1){	
			if(p == -1)break;
			ans ++;
			local = p;
			p = -1;
		}
		if(cow[i].left <= local + 1 && cow[i].right >= local + 1){
			p = max( p , cow[i].right);
			if(p >= t){
				ans ++;
				break;
			}
		}
	}
	if(p >= t)cout << ans << endl;
	else cout << -1 << endl;  
}