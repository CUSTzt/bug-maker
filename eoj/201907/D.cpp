#include<bits/stdc++.h>
using namespace std;	
long long n;
long long q;
long long he(long long a,long long b){
	long long f=0;
	long long g=0;
	if(a+b>=n-1){
		
		f=(a+b-n+2);
	}
	if(a>=n/2 && b>=n/2 && n%2==1){
		g--;
	}
	//cout<<min(a,b)+1+f<<endl;
	return min(a,b)+1+f+g;
}
int main(){
	scanf("%lld %lld",&n,&q);
	for(long long i=0,a,b,c,d;i<q;i++){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		a--;
		b--;
		long long ans=he(c,d)-he(c,b)-he(a,d)+he(a,b);
		printf("%lld\n",ans);
	}
}
/*
4 2
0 1 1 3
1 1 3 3
*/
/*
1000000000000000000 2
1000000000000000000 1000000000000000000 1000000000000000000 1000000000000000000
*/