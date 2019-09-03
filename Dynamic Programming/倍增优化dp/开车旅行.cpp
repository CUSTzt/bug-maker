//others
//我们在DP中把“天数”作为阶段   所在城市作为另一维 状态， 用倍增dp进行优化
//
//
#include <set>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100006, INF = 0x3f3f3f3f;
int n, m, h[N], x[N], s[N], ga[N], gb[N], w;
int f[18][N][2], da[18][N][2], db[18][N][2], la, lb;
multiset<pair<int, int> > st;
multiset<pair<int, int> >::iterator it, it1, it2, it3, it4;

void calc(int S, int X) {   //calc(S, X)的意思是“从城市S出发最多行驶X公里”时候  A和B分别行驶 了多长的路程
	la = lb = 0;
	int p = S;
	for (int i = w; i >= 0; i--)
		if (f[i][p][0] && la + lb + da[i][p][0] + db[i][p][0] <= X) {
			la += da[i][p][0];
			lb += db[i][p][0];
			p = f[i][p][0];
		}
}

int main() {
	cin >> n;
	w = log(n) / log (2);
	for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
	cin >> x[0] >> m;
	for (int i = 1; i <= m; i++) scanf("%d %d", &s[i], &x[i]);
	h[0] = 0;
	st.insert(make_pair(INF, 0));
	st.insert(make_pair(-INF, 0));
	st.insert(make_pair(INF, 0));
	st.insert(make_pair(-INF, 0));
	for (int i = n; i; i--) {  
	//  预处理小A和小B从每个城市i出发，沿前进方向行驶到下一个城市，分别记为ga[i],gb[i]
	//  ga[i]等于i+1~N中使dist(i, j)取得最小值的城市j  gb[i]同理
	//  我们用类似于0x13中 “邻值查找” 的方法进行预处理
		st.insert(make_pair(h[i], i));
		it = st.find(make_pair(h[i], i));
		it1 = (++it);
		it2 = (++it);
		it3 = (--(--(--it)));
		it4 = (--it);
		int a = (*it3).first != -INF ? h[i] - (*it3).first : INF;
		int b = (*it1).first != INF ? (*it1).first - h[i] : INF;
		if (a <= b) {
			gb[i] = (*it3).second;
			a = (*it4).first != -INF ? h[i] - (*it4).first : INF;
			ga[i] = (a <= b ? (*it4).second : (*it1).second);
		} else {
			gb[i] = (*it1).second;
			b = (*it2).first != INF ? (*it2).first - h[i] : INF;
			ga[i] = (a <= b ? (*it3).second : (*it2).second);
		}
	}
	//f[i][j][k]表示从城市j出发，两人共行驶2^i天，k先开车，最终会到达的城市
	//k = 0表示 小A先开车   k = 1表示小B先开车
	for (int i = 1; i <= n; i++) {
		f[0][i][0] = ga[i];
		f[0][i][1] = gb[i];
	}
	for (int i = 1; i <= n; i++) {
		f[1][i][0] = f[0][f[0][i][0]][1];
		f[1][i][1] = f[0][f[0][i][1]][0];
	}
	for (int i = 2; i < w; i++)
		for (int j = 1; j <= n; j++) {
			f[i][j][0] = f[i-1][f[i-1][j][0]][0];
			f[i][j][1] = f[i-1][f[i-1][j][1]][1];
		}
	for (int i = 1; i <= n; i++) {
		da[0][i][0] = abs(h[i]-h[ga[i]]);
		db[0][i][1] = abs(h[i]-h[gb[i]]);
		da[0][i][1] = db[0][i][0] = 0;
	}
	for (int i = 1; i <= n; i++) {
		da[1][i][0] = da[0][i][0];
		da[1][i][1] = da[0][f[0][i][1]][0];
		db[1][i][0] = db[0][f[0][i][0]][1];
		db[1][i][1] = db[0][i][1];
	}
	for (int i = 2; i < w; i++)
		for (int j = 1; j <= n; j++) {
			da[i][j][0] = da[i-1][j][0] + da[i-1][f[i-1][j][0]][0];
			da[i][j][1] = da[i-1][j][1] + da[i-1][f[i-1][j][1]][1];
			db[i][j][0] = db[i-1][j][0] + db[i-1][f[i-1][j][0]][0];
			db[i][j][1] = db[i-1][j][1] + db[i-1][f[i-1][j][1]][1];
		}
		//以上的算法 在O（Nlog N ）的时间内计算出所有“行驶天数为2 的整数次幂 ” 的状态
	calc(1, x[0]);  //calc(S, X)的意思是“从城市S出发最多行驶X公里”时候  A和B分别行驶 了多长的路程
	double ans1[2] = {1, (lb ? (double)la / lb : INF)};
	for (int i = 2; i <= n; i++) {
		calc(i, x[0]);
		if ((double)la / lb < ans1[1] || (((double)la / lb == ans1[1]) && h[i] > h[(int)ans1[0]])) {
			ans1[0] = i;
			ans1[1] = (double)la / lb;
		}
	}
	cout << ans1[0] << endl;
	for (int i = 1; i <= m; i++) {
		calc(s[i], x[i]); 
		printf("%d %d\n", la, lb);
	} 
	return 0;
}

// 总的复杂度是 O((N+M)logN)