//当数值范围太大的时候,可以先进行离散化,再利用树状数组来计算,不过离散化本身就要通过排序,所以不如用归并.
#define lowbit(x) (x)&(-x)
int ask(int x){
	int ans = 0; 
	for( ; x; x -= lowbit(x))ans += c[x];
		return ans;
}
void add(int x,int y){
	for(; x <= N; x += lowbit(x))c[x] += y ;
}

for(int i = n; i ; i--){
	ams +=ask(a[i] - 1);
	add(a[i] , 1);
}