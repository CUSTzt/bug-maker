void discrete(){  //离散化
	sort(a+1,a+n+1);
	for(int i =1; i <= n ;i++){  //也可以用stl中的unique函数
		if(i == 1 ||a[i] != a[i-1])
			b[++m] = a[i];
	}
}

int query(int x){ //查询x映射为哪个1~m之间的整数
	return lower_bound(b+1,b+m+1,x)-b;
}