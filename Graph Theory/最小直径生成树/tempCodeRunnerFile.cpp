#include<bits/stdc++.h>

using namespace std;
constexpr int maxn = 5100;
constexpr int INF = 0x3f3f3f3f;
int stx , sty , edy, edx;
struct Node {
	int x, y , stp , fx;
};
char a[maxn][maxn];
constexpr int dx[] = {0 , 0 , 1 , -1};
constexpr int dy[] = {1, -1, 0 , 0};
int n , m, zw[maxn][maxn];
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m ;
	cin >> stx >> sty >> edx >> edy;
	memset(zw, 0x3f , sizeof zw);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	function<bool(int , int)> check = [&](int x, int y){
		if(a[x][y] == '1' || x< 0 || y < 0 || x >= n || y >= m) return 1;
		return 0;
	};
	queue<Node> q;
	q.push(Node{stx , sty , -1 , 0});
	while(q.size()){
		auto fr = q.front();
		q.pop();
		int x = fr.x, y = fr.y, fx = fr.fx, tp = fr.stp;
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i], yy = y + dy[i];
			if(i != fx && fx != -1){
				tp++;
			}
			if(zw[xx][yy] > tp){
				zw[xx][yy] = tp;
				q.push(Node{xx, yy , i , tp});
			}
		}
	}
	cout << (zw[edx][edy] == INF ? -1 : zw[edx][edy]) << endl;
}