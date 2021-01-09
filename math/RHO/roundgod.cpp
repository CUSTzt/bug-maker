#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
const int N = 3e7 + 5;
vector<int> g[maxn];
ll c[maxn],b[maxn], ans[maxn];
int n, m, k, col;
const int S=20;//随机算法判定次数，S越大，判错概率越小
 
ll Mult_mod (ll a,ll b,ll c)  //减法实现比取模速度快
{    //返回(a*b) mod c,a,b,c<2^63
	a%=c;
	b%=c;
	ll ret=0;
	while (b)
	{
		if (b&1)
		{
			ret+=a;
			if (ret>=c) ret-=c;
		}
		a<<=1;
		if (a>=c) a-=c;
		b>>=1;
	}
	return ret;
}
 
//计算  x^n %c
ll Pow_mod (ll x,ll n,ll mod) //x^n%c
{
    if (n==1) return x%mod;
    x%=mod;
    ll tmp=x;
    ll ret=1;
    while (n)
    {
        if (n&1) ret=Mult_mod(ret,tmp,mod);
        tmp=Mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}
 
 
//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool Check (ll a,ll n,ll x,ll t)
{
    ll ret=Pow_mod(a,x,n);
    ll last=ret;
    for (int i=1;i<=t;i++)
    {
        ret=Mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true; //合数
        last=ret;
    }
    if (ret!=1) return true;
    return false;
}
 
// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;
bool Miller_Rabin (ll n)
{
    if (n<2) return false;
    if (n==2) return true;
    if ((n&1)==0) return false;//偶数
    ll x=n-1;
    ll t=0;
    while ((x&1)==0) {x>>=1;t++;}
    for (int i=0;i<S;i++)
    {
        ll a=rand()%(n-1)+1; //rand()需要stdlib.h头文件
        if (Check(a,n,x,t))
            return false;//合数
    }
    return true;
}
 
//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
 
ll factor[N];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组下标从0开始
 
ll Gcd (ll a,ll b)
{
    if (a==0) return 1;  //???????
    if (a<0) return Gcd(-a,b);
    while (b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}
 
ll Pollard_rho (ll x,ll c)
{
    ll i=1,k=2;
    ll x0=rand()%x;
    ll y=x0;
    while (true)
    {
        i++;
        x0=(Mult_mod(x0,x0,x)+c)%x;
        ll d=Gcd(y-x0,x);
        if (d!=1 && d!=x) return d;
        if (y==x0) return x;
        if (i==k) {y=x0;k+=k;}
    }
}
 
//对n进行素因子分解
void Findfac (ll n)
{
    if(Miller_Rabin(n)) //素数
    {
        factor[col++]=n;
        return;
    }
    ll p=n;
    while (p>=n) p=Pollard_rho(p,rand()%(n-1)+1);
    Findfac(p);
    Findfac(n/p);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
        Findfac(c[i]);
    sort(factor, factor + col);
    col = unique(factor, factor + col) - factor;
    //assert(0);
    for (int i = 0; i < col ;i++)
        cout << factor[i] << ' ';
    cout << endl;
}