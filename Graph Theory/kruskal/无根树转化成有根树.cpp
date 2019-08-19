#include <bits/stdc++.h>
using namespace std;


const int maxn = 1005;
//存入边
int n; //n个结点，包含n-1条边
vector <int > G[maxn];
int p[maxn];
void read_tree(){
	int u,v;
	scanf("%d",&n);
	for(int i = 0; i < n-1;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
//转化过程
void dfs(int u,int fa ){   //递归转化以u为根的子树，u的父结点为fa
	int d = G[u].size();   //结点u的相邻点的个数
	for(int i = 0; i < d; i++){
		int v = G[u][i];   //结点u的第i个相邻点v
		if(v != fa)dfs(v,p[v] = u);  //把v的父结点设置为u，然后递归转化以c为根的子树
	}
}


int main(){
	int root ;
	//5cin>>n;
	read_tree();
	cin>>root ;
	p[root] = -1;
	dfs(root , -1);
	for(int i = 1;i <= n;i++){
		 cout << "R[" << i << "] : " << p[i] << endl;
	}
}