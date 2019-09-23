/*************************************
 * Author : miniLCT
 * More : You build it. You run it
 ************************************/
//此题用递归和分治也可以写， 现在用乘法逆元来写
//由算术基本定理的“约数和理论”可知A^B的所有约数和为(1+p1+p1^2………p1^(B*c1))*…………*(1+pn+pn^2………pn^(B*cn))
//观察可知每一项都是等比数列  (1+p1+p1^2………p1^(B*c1))=(p1^(B*c1+1)-1)/(p1-1) 
//用快速幂计算(p1^(B*c1+1)-1)mod 9901 和(p1-1)mod 9901
//9901 是质数   所以只要（p1-1不是9901）的倍数 只需计算p1-1的乘法逆元 inv
//用乘inv代替除以(p1-1)直接计算出等比数列求和公式
//特别的 若p1 - 1是9901的倍数，此时乘法逆元不存在，但是p1 mod 9901 =1
//所以(1+p1+p1^2………p1^(B*c1) mod 9901 =  1+B*c1 （mod9901）

#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#define ll long long
#define int long long 
#define INF 0x3f3f3f3f 
#define lowbit(x) (x)&(-x)
#define FOR(i,f_start,f_end) for(int i=f_start;i<=f_end;++i) 
#define MT(x,i) memset(x,i,sizeof(x))
#define close std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000000009;
 ll mod = 9901 ;
const double PI = acos(-1.0);
const double E = exp(1);
const double EPS=1e-8;
const int maxn = 1e6+10;
/*long long multi(long long a,long long b,long long mod) {
    long long ret=0;
    while(b) {
        if(b&1)
            ret=(ret+a)%mod;
        a=(a<<1)%mod;
        b=b>>1;
    }
    return ret;
}
long long quickPow(long long a,long long b,long long mod) {
    long long ret=1;
    while(b) {
        if(b&1)
            ret=multi(ret,a,mod);  //直接相乘的话可能会溢出
        a=multi(a,a,mod);
        b=b>>1;
    }
    return ret;
}*/
int quickPow(int a, long long b,int mod) {
	int c = 1;
	for (; b; b >>= 1) {
		if (b & 1) c = (long long)c * a % mod;
		a = (long long) a * a % mod;
	}
	return c;
}
int a, b , m , ans = 1;
int p[20],c[20];
void divide(int n){  //因数分解
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
main()
{
	cin >> a >> b;
	divide(a);//分解质因数
	for(int i = 1; i <= m;i++){
		if((p[i] - 1)%mod == 0){ //没有逆元
			ans = (b*c[i] +1)%mod * ans % mod;
			continue;
		} 
		int x = quickPow(p[i],(ll)(b*c[i]+1),mod);//分子
		x = (x-1+mod)%mod;
		int y = p[i] - 1;//分母
		y = quickPow(y,mod-2,mod);
		ans = (ll)ans * x%mod*y%mod;
	}
	cout << ans<<endl;

}