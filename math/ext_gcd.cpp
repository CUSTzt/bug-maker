int gcd (int a,int b){
	return b == 0 ? a : gcd(b , a % b);
}

//找出a,b最大公因数，且求出x，y满足ax+by =gcd(a,b)。
int ext_gcd(int a, int b, int &x,int &y){
	int d = a;
	if(b != 0){
		d = ext_gcd(b , a%b ,y , x);
		y -= (a / b) * x;
	}else {
		x = 1;
		y = 0;
	}
	return d;
}