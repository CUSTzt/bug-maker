#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<queue>
#define ll long long
#define INF 1000000000
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline ll read()
{
	register ll ret=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret;
}

#define M 300005
#define P 998244353

ll a[M],b[M],x,f[M];
int n,q,mu[M],p[M*10],zero[M],cnt;
bool vis[31624000];

ll mi(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%P;
		x=x*x%P;
		y>>=1;
	}
	return ans;
}

int main()
{
	for(int i=2;i<=31623000;i++)
	{
		if(!vis[i])p[++cnt]=i;
		for(int j=1;j<=cnt&&i*p[j]<=31623000;j++)
		{
			vis[i*p[j]]=1;
			if(!(i%p[j]))break;
		}
	}
	n=read(),q=read(),x=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	for(int i=1;i<=n;i++)mu[i]=1;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=1)
		{
			ll temp=sqrt(b[i])+1;
			for(int j=1;p[j]<=temp&&b[i]!=1;j++)
			{
				if(!(b[i]%p[j]))
				{
					for(int k=i;k<=n;k++)
					{
						if(!(b[k]%p[j]))
						{
							mu[k]*=-1;
							b[k]/=p[j];
						}
						while(!(b[k]%p[j]))
						{
							mu[k]=0;
							b[k]/=p[j];
						}
					}
				}
			}
			if(b[i]!=1)
			{
				for(int k=i+1;k<=n;k++)
					{
						if(!(b[k]%b[i]))
						{
							mu[k]*=-1;
							b[k]/=b[i];
						}
						while(!(b[k]%b[i]))
						{
							mu[k]=0;
							b[k]/=b[i];
						}
					}
				b[i]=1;
				mu[i]*=-1;
			}
		}
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=(a[i]+mu[i]+x)%P;
		if(f[i]==0)zero[i]=1;
		zero[i]+=zero[i-1];
		if(f[i-1]!=0)f[i]=f[i-1]*f[i]%P; 
	}
	for(int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		if(zero[r]-zero[l-1])puts("0"); 
		else if(f[l-1]==0) printf("%d\n",f[r]);
		else printf("%d\n",f[r]*mi(f[l-1],P-2)%P);
	}
	return 0;
}

