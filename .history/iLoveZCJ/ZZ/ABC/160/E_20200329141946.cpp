#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int x,y,a,b,c,p[100005],q[100005],r[100005];
ll ans,c1,c2,c3;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for(int i=1;i<=a;i++)scanf("%d",&p[i]);
	for(int i=1;i<=b;i++)scanf("%d",&q[i]);
	for(int i=1;i<=c;i++)scanf("%d",&r[i]);
	sort(p+1,p+a+1,cmp);
	sort(q+1,q+b+1,cmp);
	sort(r+1,r+c+1,cmp);
	int nowi=1,nowj=1,nowk=1;
	for(int i=1;i<=x+y;i++)
	{
		if(r[nowk]>=p[nowi]&&r[nowk]>=q[nowj])
		{
			ans+=r[nowk];
			nowk++;
			continue;
		}
		if(p[nowi]>q[nowj])
		{
			if(nowi<=x)
			{
				ans+=p[nowi];
				nowi++;
			}
			else
			{
				if(r[nowk]>=q[nowj])
				{
					ans+=r[nowk];
					nowk++;
				}
				else
				{
					ans+=q[nowj];
					nowj++;
				}
			}
		}
		else
		{
			if(nowj<=y)
			{
				ans+=q[nowj];
				nowj++;
			}
			else
			{
				if(r[nowk]>=p[nowi])
				{
					ans+=r[nowk];
					nowk++;
				}
				else
				{
					ans+=p[nowi];
					nowi++;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
