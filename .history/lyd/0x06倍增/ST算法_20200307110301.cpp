//在RMQ问题（区间最值问题）中，ST算法就是倍增的产物
//ST算法能在O(NlogN)的时间预处理之后，以O(1)的时间复杂度在线回答数列A中下标
//在L~R之间的数的最大值是多少
//设F[i,j]表示数列A中下标在子区间 [i,i+2^j-1]里的数的最大值，也就是从i开始的
//2^j个数的最大值
//
void ST_prework(){
	for(int i = 1; i <= n;i++)
		f[i][0] = a[i];
	int t = log(n) / log(2) +1;
	for(int j = 1; j < t; j++)
		for(int i = 1; i <= n - (1<<j) +1; i++)
			f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		//这个式子的意义就是 长度为2^j的子区间的最大值是左右两半长度为2^(j-1)
		//的子区间的最大值中的较大的一个
}

int ST_query(int l ,int r){
	int k = log(r-l+1) / log(2);
	return max(f[l][k], f[r-(1<<k)+1][k]);
}