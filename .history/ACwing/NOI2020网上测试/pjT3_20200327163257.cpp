#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
using namespace std;
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 111
#define MAXM 2511
ll n;
struct mat
{
    ll a[MAXN][MAXN];
    mat(ll t[MAXN][MAXN])
    {
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j)a[i][j]=t[i][j];
    }
    mat(){}
    mat operator *(const mat& t)//广义矩阵乘法
    {
        ll sum[MAXN][MAXN];
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j)
            {
                sum[i][j]=a[i][1]+t.a[1][j];
                for(ll k=2;k<=n;++k)
                    umin(sum[i][j],a[i][k]+t.a[k][j]);
            }
        return mat(sum);
    }
    mat Qpow(ll p)//矩阵快速幂,求a^p
    {
        --p;
        mat res=*this,cur=*this;
        while(p)
        {
            if(p&1)res=res*cur;
            cur=cur*cur;
            p>>=1;
        }
        return res;
    }
}a;//a就是dis1

ll dis[MAXN][MAXN];//dis0
void Floyd(ll n)
{
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j)
                umin(dis[i][j],dis[i][k]+dis[k][j]);
}
struct edge
{
    ll u,v,w;
}e[MAXM];
int main()
{
    n=read();
    ll m=read(),k=read();
    memset(dis,0x3f,sizeof dis);
    for(ll i=1;i<=n;++i)dis[i][i]=0;
    a=mat(dis);
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read(),w=read();
        umin(dis[u][v],w);
        e[i]=edge{u,v,w};
    }
    Floyd(n);
    for(int i =1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dis[i][j] <<" \n"[j==n];
        }
    }
    if(k==0)
    {
        printf("%lld",dis[1][n]);
        return 0;
    }
    for(ll i=1;i<=m;++i)
    {
        ll u=e[i].u,v=e[i].v,w=e[i].w;
        for(ll s=1;s<=n;++s)
            for(ll t=1;t<=n;++t)
                umin(a.a[s][t],dis[s][u]-w+dis[v][t]);
    }

    for(int i = 0; i <=  n;i++){
        for(int j = 0 ; j <= n; j++){
            cout << a.a[i][j] <<" \n"[j==n];
        }
    }
    cout << "---\n" << endl ;

    for(int i = 0; i <=  n;i++){
        for(int j = 0 ; j <= n; j++){
            cout << a.Qpow(k).a[i][j] <<" \n"[j==n];
        }
    }
    for(int i = 0; i <=  n;i++){
        for(int j = 0 ; j <= n; j++){
            cout << a.Qpow(k).a[i][j] <<" \n"[j==n];
        }
    }
    printf("%lld",a.Qpow(k).a[1][n]);
    return 0;
}
