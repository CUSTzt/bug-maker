#include<bits/stdc++.h>
const int a[6]={4,8,15,16,23,42};
int ans[4];
int p[6];
int main(){
	for(int i=0;i!=4;++i){
		printf("? %d %d\n",1,i+2);
		fflush(stdout);
		scanf("%d",&ans[i]);
		p[0]=std::__gcd(p[0],ans[i]);
	}
	if(p[0]==30)
		p[0]=15;
	else if(p[0]==46)
		p[0]=23;
	for(int i=0;i!=4;++i){
		p[i+1]=ans[i]/p[0];
	}
	int sum=0;
	for(int i=0;i!=6;++i)
		sum+=a[i];
	for(int i=0;i!=5;++i)
		sum-=p[i];
	p[5]=sum;
	printf("! ");
	for(int i=0;i!=6;++i)
		printf("%d ",p[i]);
	puts("");
	fflush(stdout);
	return 0;
}