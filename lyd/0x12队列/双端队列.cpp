#include<cstdio>
#include<algorithm>
using namespace std;
pair<int,int> a[200100];
int n,ans=1,last=0x7fffffff;
bool flag;
int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",&a[i].first),a[i].second=i;
	sort(a,a+n);
	for (int i=0,p,pp; i<n; i++) {
		p=a[i].second;
		while(i+1<n && a[i+1].first==a[i].first) i++;
		pp=a[i].second;
		if (flag)
			if (last<p) last=pp;
			else ans++,last=p,flag=0;
		else 
			if (last>pp) last=p;
		    else last=pp,flag=1;
	}
	printf("%d",ans);
}


