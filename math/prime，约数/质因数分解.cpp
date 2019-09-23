//  质因数分解： 扫描2~√n  的数整除，并且记录个数  O(√n)
int p[maxn],c[maxn];
int m ;
void divide(int n){
	m = 0;
	int sqrtn = sqrt(n);
	for(int i = 2; i <= sqrtn; i++){
		if(n % i == 0){  //i是质数
			p[++m] = i;
			c[m] = 0;
			while(n % i == 0)n /= i,c[m]++; // 除掉所有的i
		}
	}
	if(n > 1)//n是质数
		p[++m] = n, c[m] = 1;
	/*for(int i = 1; i <= m; i++)
		cout << p[i] << '^' << c[i] <<endl;*/
}