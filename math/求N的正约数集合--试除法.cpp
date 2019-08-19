//复杂度 O (√n)
int factor[1600] , m = 0;
for(int i = 1; i * i <= n; i++){
	if(n % i == 0){
		factor[++m ] = i;
		if(i != n/i) factor[++m] = n/i ;
	}
}
for(int i = 1; i <= m; i++){
	cout << factor[i] <<endl;
}