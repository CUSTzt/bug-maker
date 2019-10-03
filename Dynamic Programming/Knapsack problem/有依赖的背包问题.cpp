//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string.h>
//using namespace std;
const int maxn = 110;
int n , V, v[maxn], w[maxn] , p[maxn], cnt , root;
int head[maxn] , edge[maxn], next[maxn] , f[maxn][maxn];
void add(int x, int y ){
	edge[cnt] = y;
	next[cnt] = head[x];
	head[x] = cnt++;
}
void dfs(int x){
	for(int i = head[x]; i != -1;i = next[i]){
		int y = edge[i];
		dfs(y);
		for(int j = V - v[x]; j >= 0;j--){
			for(int k = 0; k <= j;k++){
				f[x][j] = std::max(f[x][j] , f[x][j - k] + f[y][k]);
			}
		}
	}
	for(int i = V; i >= v[x]; i--)f[x][i] = f[x][i-v[x]]+w[x];
	for(int i = 0; i < v[x]; i++)f[x][i] = 0;
}

int main()
{
	memset(head ,0xff,sizeof(head));
	std::cin >> n >> V;
	for(int i = 1 ; i <= n;i++){
		std::cin >> v[i] >> w[i] >> p[i];
		if(p[i] == -1){
			root = i;
		} else {
			add(p[i] , i);
		}
	}
	dfs(root);
	std::cout << f [root][V] << std::endl;
}