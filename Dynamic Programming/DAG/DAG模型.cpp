//DAG 模型  Directed Acyclic Graph
//
//有n个矩阵，每个矩阵可以用两个整数a,b描述，表示它的长和宽。矩阵X(a,b)可以嵌套在矩阵Y(c,d)中当且仅当a<c,b<d，或者b<c,a<d。
//
int dp(int i){
	int& ans = d[i]; //对ans的读写都是在d[i]上进行的
	if(ans > 0)return ans;
	ans  = 1;
	for(int j = 1; j <= n; j++)
		if(G[i][j] )ans = max( ans , dp(j) + 1);
	return ans;
}

void print_ans (int i){
	printf("%d", i);
	for(int j = 1; j <= n;j++)if(G[i][j] && d[i] == d[j] + 1){
		print_ans(j);
		break;  
	}
}