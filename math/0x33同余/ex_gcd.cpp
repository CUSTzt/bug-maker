//对于任意整数a, b,存在一对整数x,y.满足ax+by=gcd(a,b)


int exgcd(int a, int b ,int & x, int &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a%b , x , y);
	int z = x;x = y;y = z - y *(a / b);
	return d;
}

//对于更一般的方程  ax+by=c 
//  x = (c/d)*x0+k*(b/d)    y = (c/d)*y0-k*(a/d)  
// k取遍整数集合，d=gcd(a,b) ,   x0,y0是 ax+by=gcd(a,b)的一组特解 并且返回a,b的最大公约数
