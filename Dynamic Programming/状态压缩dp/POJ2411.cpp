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
int n, m;
long long f[100][maxn];
bool in_s[maxn];
int main()
{
	while(cin >> n >> m&&n){
		for(int i = 0; i < 1<<m;i++){
			bool cnt = 0 , has_odd = 0;
			for(int j = 0; j < m;j++)
				if(i >> j&1)has_odd|=cnt , cnt = 0;
			else cnt ^=1;
			in_s[i] = has_odd | cnt ? 0 : 1;
		}
		f[0][0] = 1;
		for(int i = 1; i <= n;i++){
			for(int j = 0; j < 1<<m;j++){
				f[i][j] = 0;
				for(int k = 0; k < (1<<m);k++)
					if((j&k)==0&&in_s[j|k])
						f[i][j]  += f[i-1][k];
			}

		}
		cout << f[n][0]<<endl;
	} 
}
