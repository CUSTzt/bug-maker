#include<bits/stdc++.h>
using namespace std;
const int N=1E5+100;
int n,m,t,c[N],r[N],s[N];
long long solve(int c[],int n) {
	memset(s,0,sizeof(s));
	for(int i=1; i<=n; i++)
		s[i]=s[i-1]+c[i]-t/n;
	sort(s+1,s+1+n);
	long long sum=0;
	int k=(n+1)/2;
	for(int i=1; i<=n; i++)
		sum+=abs(s[i]-s[k]);
	return sum;
}
int main() {
	cin>>n>>m>>t;
	int a,b;
	for(int i=0; i<t; i++) {
		cin>>a>>b;
		c[a]++;
		r[b]++;
	}
	if(t%m&&t%n) {
		puts("impossible");
		return 0;
	}
	if(t%n==0&&t%m==0) {
		cout<<"both "<<solve(c,n)+solve(r,m)<<endl;
	} else if(t%n==0)cout<<"row "<<solve(c,n)<<endl;
	else cout<<"column "<<solve(r,m)<<endl;
	return 0;
}
