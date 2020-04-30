/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-15 12:11:29
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
//考虑欧拉回路，奇数偶数分开处理
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 2e6+100;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const int MID = 2*1e6;
ll mod = 1e9+7;
struct Edge{
	int v, nxt;
}e[maxn];
int n , m , l , r , vis[maxn] , head[maxn], cnt = 0, deg[maxn];
stack<int >s;
std::vector<int > path;
void add(int u , int v){
	e[cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}
int dfs(int u){//一次找一条路
	while(deg[u]){ 
		//cout << "deg["<<u<<"] === " << deg[u] << endl;
		int to = -1, k = -1;
		s.push(u);
		for(int i = head[u]; i != -1; i = e[i].nxt ){
			if(vis[i])continue;
			if(to == -1 && k == -1){
				to = e[i].v;
				k = i;
				break;
			}
		}
		//寻找他的下一个可到达的最小顶点
		vis[k] = 1; 
		vis[k ^ 1] = 1;
		deg[u] --, deg[to] -- ;
		u = to;
	}
	s.push(u);
	return u;
}
int check(int x){
	if(x & 1){
		int ans = x*(x-1)/2+1;
		return ans;
	}else {
		return x*x/2;
	}
}
void work(int n , int m){
	//cout << "work" << endl;
	memset(head ,  -1, sizeof (head));
	for(int i = 1; i <= n; i++){
		deg[i] = n-1;
		for(int j = i+1; j <= n; j++){
			add(i , j);
			add(j , i);
		}
	}
	if(n % 2 == 0){
		for(int i = 2; i < n-1 ; i+=2){
			add(i , i+1),add(i+1 , i);
			deg[i] ++, deg[i+1]++;
		}
	}
	dfs(1);
	//cout << "oio" << endl;
	while(s.size()){
		int x = s.top();s.pop();
		if(deg[x] == 0)path.push_back(x);
		else dfs(x);
	}
	cout << n << endl;
	cout << path[0];
	for(int i = 1; i  < path.size(); i++){
		//cout << path[i] << " ";
		printf(" %d", path[i]);
	}
	for(int i = path.size(); i < m; i++){
		//cout << 1;
		printf(" 1");
		//if(i != m-1)cout << " ";
	}cout << endl;
	cout << endl;
}
int32_t main(){
	cin >> n ;
	l = 1; r = 1e9;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(check(mid) <= n){
			m = mid , l = mid + 1;
		}else r = mid - 1;
	}
	if(n > MID){
		cout << m << endl;
	}else{
		//cout << "d" << endl;
		work(m , n);
	} 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
