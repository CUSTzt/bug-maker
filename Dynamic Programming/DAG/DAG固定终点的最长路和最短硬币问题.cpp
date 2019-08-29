//有n种硬币，面值分别为 V1,V2,…,Vn。每种都有无限多。给定非负整数S，问可以选用多少个硬币，
//使得面值之和恰好为S？输出硬币数目的最小值和最大值。 1<=n<=100,0<=S<=10000,1<=Vi<=S;


//d[i]  从结点i出发到结点0的最长路径长度
//要注意到有 可能结点S不能真的到达,返回值应该是0 
//处理方法  增加一个vis数组 vis[i]表示状态i是否被访问过
int dp(int S){
	if(vis[S])return d[S];
	vis[S] = 1;
	int& ans = d[S];
	ans = -(1<<30);
	for(int i = 1; i <= n;i++)if(S >= V[i])ans = max(ans, dp[S-V[i]]+1 );
	return ans ;
}

// 求最小最大两个值   记忆化搜索两次  
minv[0] = maxv[0] = 0;
for(int i =1; i <= S;i++){
	minv[i] = INF; maxv[i] = -INF;
}
for(int i = 1; i <= S;i++)
	for(int j = 1; j <= n; j++)
		if(i >= V[j]){
			minv[i] = min(minv[i] , minv[i - V[j]] + 1) ;
			maxv[i] = max(maxv[i] , maxv[i - V[j]] + 1) ;
		}
printf("%d %d\n",minv[S], maxv[S] );

//输出字典序最小的方案
void print_ans(int* d , int S){
	for(int i = 1; i <= n ; i++){
		if(S >= V[i] && d[S] == d[S - V[i]]+1){
			printf("%d" , i);
			print_ans(d, S - V[i]);
			break;
		}
	}
}

//分别调用 print_ans(minv, S) print_ans(maxv, S)来输出路径
  

//打印路径的方法也是可行的 
//实现 : 递推时 用min_coin[S]来记录满足min[S-V[i]]+1的最小的i,打印路径时就可以省去print_ans函数中的
//循环 了,递归就改成了迭代
for(int i = 1; i <= S;i++){
	for(int j = 1; j <= n;j++){
		if(i >= V[j]){
			if(min[i] > min[i - V[j]]+1){
				min[i] = min[i-V[j]]+1;
				min_coin[i] = j;
			}
			if(max[i] < max[i - V[j]]+1){
				max[i] = max[i-V[j]]+1;
				max_coin[i] = j;
			}
		}
	}
}

void print_anss(int *d, int S){
	while(S){
		printf("%d ", d[S]);
		S -= V[d[S]];
	}
}