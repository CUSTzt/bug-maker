/*************************************
 * Author : miniLCT
 * More : You build it. You run it
 ************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
const int inf = 0x3f3f3f3f;
using namespace std;
int dp[101][77][77];
int sg[101];
int n , m , idx;
int s[77]; // 合法的摆放集合
int cnt0[77]; // 合法摆放方案的具体摆放个数，即二进制下1的个数
/*int get_one(int x ){   //统计有几个1
	int cnt = 0;
	while(x)x &= (x-1),++cnt;
	return cnt; 
}*/
bool ok(int x){
	//相邻两个P之间要有两个H
	if(x & (x << 1))return false;  
	if(x & (x << 2))return false;
	return true;
}
void init(){
	idx = 0;
	int end = 1 << m;
	for(int i = 0; i < end;i++){
		if(ok(i)){
			//s保存合法方案的集合
			s[idx] = i;
			//cnt0保存合法方案的摆放个数， 二进制位1的个数
			cnt0[idx++] = __builtin_popcountll(i);
			//cnt0[idx++] = get_one(i);
		}
	}
}
bool valid(int i , int x){
	if (sg[i] & x)return false;
	return true;
}
int solve(){
	int ans = 0;
	memset(dp, -1,sizeof(dp));
	dp[0][0][0] = 0;
	for(int j = 0; j < idx; j++){
		if(valid(1, s[j])){
			dp[1][j][0] = cnt0[j];
			//考虑n==1的情况
			ans = max(ans , dp[1][j][0]);
		}
	}
	for(int i = 2; i < n+1;i++){
		//valid()函数判断， 第i行  ， 用s[j]是否合法
		for(int j = 0; j < idx;j++){
			if(valid(i, s[j])){
				//i行跟 i-1行的方案， 满足，互相炸不到对方
				for(int k = 0; k < idx;k++){
					if(valid(i-1, s[k])&&(s[j]&s[k])==0){	
						int last = 0;
						//i-2行同上
						for(int l = 0; l < idx;l++){
							if(dp[i-1][k][l] != -1 && (s[l]&s[j])==0 && valid(i-2, s[l])){
								last = max(last , dp[i-1][k][l]);
							}
						}
						dp[i][j][k] = max(dp[i][j][k], last + cnt0[j]);
				        if(i == n) 
				        	ans = max(ans, dp[i][j][k]);
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n;i++){
		for(int j = 0; j < m;j++){
			char aa;
			cin>>aa;
			if(aa=='H') 
				sg[i] |= (1<<(m-1-j));
		}
	}
	init();
	cout << solve()<<endl;
	return 0;
}