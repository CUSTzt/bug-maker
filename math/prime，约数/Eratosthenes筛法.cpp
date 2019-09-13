//复杂度 ： O(Nloglog N)

const int maxn = 1e6+10;
int v[maxn];
void primes(int n ){
	memset(v, 0, sizeof(v));//合数标记
	for(int i = 2; i <= n;i++){
		if(v[i]) continue;
		cout << i << endl; //i 是质数
		for(int j = i ; j <= n/i;j++)v[i*j] = 1;
	}

}