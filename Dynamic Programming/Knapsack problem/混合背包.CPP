 //https://www.acwing.com/problem/content/7/
 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-10-03 11:38:11
 # @Description: You build it.You run it
 # @More: If lots of AC,try BF,dfs,DP
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define pb push_back
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int N, V, kind , v, w;
struct Node{
	int kind, v, w;
	Node(){}
	Node(int kind, int v ,int w):kind(kind),v(v),w(w){}
};
vector<Node> knapsack;
int f[maxn];
int main()
{
	cin >> N >> V;
	for(int i = 0; i < N;i++){
		cin >> v >> w >> kind;
		if(kind == -1){
			knapsack.pb({kind, v , w});
		} else if(kind == 0){
			knapsack.pb({kind, v , w});
		} else {
			for(int k = 1; k <= kind;k *= 2){
				kind -= k;
				knapsack.pb({-1 , v*k , w*k});
			}
			if(kind > 0)knapsack.pb({-1, v*kind , w*kind});
		}
	}
	for(auto x : knapsack){
		if(x.kind < 0){
			for(int j = V;j >= x.v;j--)
				f[j] = max(f[j], f[j - x.v] + x.w);
		}else {
			for(int j =x.v;j <= V;j++)
				f[j] = max(f[j], f[j - x.v] + x.w);
		}
	}
	cout << f[V] << endl;
	//cout << *max_element(f,f+V+1)  << endl;
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/