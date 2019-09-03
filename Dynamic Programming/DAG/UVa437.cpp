/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-23 10:03:27
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
#define pb push_back
const int maxn = 50;

using namespace std;
struct  Node{
	int x, y , z;
	Node(int x ,int y ,int z) :x(x),y(y),z(z){}
	Node(){}
	bool operator < (const Node &n)const {
		return (x < n.x && y < n.y)||(x<n.y&&y<n.x);
	}
};
int n , d[maxn * 3],G[maxn * 3][maxn * 3];
std::vector<Node> vec;
int dp(int i , int h ) // 以i开头可以得到的最大高度
{
	int& ans = d[i];
	if(ans > 0)return ans;
	ans = h;
	for(int j = 0; j < n * 3;j++){
		if(G[i][j])ans =  max(ans,dp(j,vec[j].z)+h);
	}
	return ans;
}
int main()
{
	int cnt = 0;
	while(cin>>n&&n){
		//cout << 1<<endl;
		vec.clear();
		memset(G,0, sizeof(G));
		memset(d,0, sizeof(d));
		for(int i  = 0; i < n;i++){
			int x,y , z;
			cin>>x>>y>>z;
			//cout << 2<<endl;
			vec.pb(Node(x,y,z));
			vec.pb(Node(x,z,y));
			vec.pb(Node(z,y,x));
		}
		sort(vec.begin(), vec.end());
		for(int i = 0; i < n*3;i++){
			for(int j = 0; j < n*3;j++){
				if(vec[i] < vec[j])
					G[i][j] = 1;
			}
		}
		//cout <<3<<endl;
		int result = -1;
		for(int i =0; i < n*3;i++){
			result = max(result , dp(i,vec[i].z));
		}
		//cout <<4<<endl;
		printf("Case %d: maximum height = %d\n",++cnt ,result );
	}
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
