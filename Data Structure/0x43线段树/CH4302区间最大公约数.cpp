 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-10 18:55:35
 # @Description: You build it.You run it
 ***********************************************/

//gcd(a, b ) = gcd(a , b-a) 更相减损术
//gcd(a−nb,b)=gcd(a,b)。
//(a,b,c)=((a,b),(b,c))=((a,b−a),(b,c−b))=(a,b−a,b,c−b)
//由于(b−a,b)=(a,b−a)所以(a,b,c)=(a,b−a,c−b)   
//gcd(a, b ) = gcd(a , -b)  数值加减过程中会产生负数，gcd约定没有负数， 所以用这个式子来搞定负数   注意只是 运算时候取负数， 不能改变叶子节点
//显然有 gcd(a, b ) = gcd (a, -b) 但是 (a+1 , b)和 (a+1 , -b)不一定相等
//差分操作是a[x]+d,a[y+1]-d;这个时候就可能出现y+1越界的情况。需要及时特判掉。


//所以解题思路是：
//gcd(x,y,z)=gcd(x,y-x,z-y) 此性质对于任意多个整数都能成立
// 所以 构造一个长度为N的新序列B,B[i] = A[i]-A[i-1] B[1]可以为任何值  数列B称为A的差分序列  用线段树维护序列B的区间最大公约数
//查询Q l r 就等于求出gcd(A[l], ask(1, l+1, r))
//在指令 C l r d 下，只有B[l] 加了d ，B[r+1] 减去d  所以维护B的线段书上只需要两次单点修改即可。
//另外 询问时需要数列A的值， 可以额外用一个支持“区间增加，单点查询”的树状数组对A进行维护
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define lowbit(x) x&(-x)
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 5e5;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , m ;
struct SegmentTree{
	int l, r, dat;
}t[maxn*4];
int a[maxn], b[maxn] , c[maxn];
void build(int p , int l , int r){
	t[p].l = l,t[p].r = r;
	if(l == r){t[p].dat = c[l];return ;}
	int mid = (l + r) / 2 ;
	build(p*2, l , mid);
	build(p*2+1, mid+1, r);
	t[p].dat = __gcd(t[p*2].dat , t[p*2+1].dat);
}
void update(int p , int x, int v){
	if(x > n)return;
	if(t[p].l == t[p].r){t[p].dat = t[p].dat + v;return ;}
	int mid = (t[p].l + t[p].r) / 2;
	if(x <= mid)update(p*2, x, v);
	else update(p*2+1 , x , v);
	t[p].dat = __gcd(t[p*2].dat, t[p*2+1].dat);
}
int ask(int p , int l , int r ){
	if(l > r)return 0;
	if(l < t[p].l && r > t[p].r)return abs(t[p].dat);
	int mid = (t[p].l + t[p].r) / 2;
	int vl = 0 , vr = 0;
	if(l <= mid)vl = ask(p*2, l , r);
	if(r > mid) vr = ask(p*2+1, l , r);
	return abs(__gcd(vl, vr));
}
void add(int x, int v, int *b){
	for(; x <= n;x += lowbit(x))b[x] += v;
}
int query(int x, int *b){
	int res = 0;
	for(; x; x -= lowbit(x))res += b[x];
	return res;
}
main()
{
	close;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		c[i] = a[i] - a[i-1];
	}
	build(1, 1, n);
	char ch;
	int xx , yy ,zz;
	for(int i = 0; i < m;i++){
		cin >> ch;
		if(ch == 'Q'){
			cin >> xx >> yy;
			int ans =__gcd(a[xx]+query(xx,b), ask(1,xx + 1,yy));
			//int anss = __gcd(a[xx] + query(xx,b), ask(a, xx+1, yy));
			//cout << __gcd(a[xx] + query(xx, b), ask(a, xx+1, yy))<<endl;
			cout << ans <<endl;
	
		}
		if(ch == 'C'){
			cin >> xx >> yy >> zz;
			update(1, xx, zz);
			update(1, yy+1, -zz);
			add(xx,zz,b);
			add(yy+1 , -zz, b); 
		}
	}


}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/