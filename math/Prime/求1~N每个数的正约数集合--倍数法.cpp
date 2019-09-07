// 用试除法 分别求1~N每个数的正约数集合 时间复杂度O(n√n)   
// 用倍数法 复杂度为O(N+N/2+N/3+……+N/N) = O(Nlog N)
// 推论：1~N 每个数的约数个数的综合大约是 NlogN
vector<int >factor[500010];
for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n / i; j++)
		factor[i * j].push_back(i);
for(int i = 1; i <= n; i++){
	for(int j = 0; j < factor[i].size(); j++)
		printf("%d ",factor[i][j] );
	cout <<endl;
}