#include<bits/stdc++.h>
#define maxl 300010
using namespace std;
 
int n,k;
long long ans;
long long dp[maxl],sum[maxl];
int q[maxl],nxt[maxl],num[maxl];
 
inline void prework()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&sum[i]);
		sum[i]+=sum[i-1];
	}
}
 
inline long long calc(int l,int r)
{
	return sum[l]+sum[r]-sum[(l+r)>>1]-sum[(l+r+1)>>1];
}
 
inline bool cmp(int i,int j,int k)
{
	long long val1=dp[i]+calc(i,k),val2=dp[j]+calc(j,k);
	if(val1==val2)
		return num[i]<num[j];
	return val1<val2;
}
 
inline int jug(long long mid)
{
	int head=1,tail=1;
	q[1]=dp[0]=0;nxt[1]=1;
	for(int i=1;i<=n;i++)
	{
		while(head<tail && nxt[head+1]<=i)
			head++;
		dp[i]=dp[q[head]]+calc(q[head],i)+mid;
		num[i]=num[q[head]]+1;
		while(head<=tail &&i<nxt[tail]&&cmp(i,q[tail],nxt[tail]))
			tail--;
		int l=nxt[tail],r=n+1,id;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(cmp(i,q[tail],mid))
				r=mid;
			else
				l=mid;
		}
		if(cmp(i,q[tail],l)) 
			id=l;
		else id=l+1;
		if(id<=n)
			q[++tail]=i,nxt[tail]=id;
	}
	return num[n];
}
 
inline void mainwork()
{
	long long l=0,r=sum[n]+1,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(jug(mid)<=k)
			r=mid;
		else
			l=mid;
	}
	if(jug(l)<=k)
		ans=dp[n]-k*l;
	else
	if(jug(l+1)<=k)
		ans=dp[n]-k*(l+1);
}
 
inline void print()
{
	printf("%lld\n",ans);
}
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		prework();
		mainwork();
		print();
	}
	return 0;
}