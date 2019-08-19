bool is_prime(int n){
	if(n < 2)return false;
	int m = sqrt(n);
	for(int i = 2; i <= m; i++)
		if(n % i == 0) return false ;
	return true;
}