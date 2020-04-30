//others
//fft leiou
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int M=13;
const ll Mod=1e9+7;
ll y[M],C[M][M],F[M][M][44];
ll fpow(ll a,ll b=Mod-2){
	a%=Mod;if(a<0)a+=Mod;ll res=1;for(;b;b>>=1,a=(a*a)%Mod)if(b&1)res=(res*a)%Mod;
	return res;
}
struct Ply{
	ll x[M];
	void clear(){memset(x,0,sizeof(x));}
	Ply(){memset(x,0,sizeof(x));}
	Ply operator +(const Ply &a)const{
		Ply ans;for(int i=0;i<M;i++)ans.x[i]=(x[i]+a.x[i])%Mod;
		return ans;	
	}
	Ply operator *(const Ply &a)const{
		Ply ans;
		for(int i=0;i<M;i++)for(int j=0;i+j<M;j++)
		ans.x[i+j]=(ans.x[i+j]+x[i]*a.x[j]%Mod)%Mod;
		return ans;
	}
	ll operator ()(ll a,int b){
		ll ans=x[b+1];for(int i=b;i>=0;i--)ans=(ans*a%Mod+x[i])%Mod;
		return ans;
	}
}A[M],B[M];
void calc(Ply &a,int n){
	Ply xx,yy;
	for(int i=0;i<=n;i++){
		xx.x[0]=y[i];
		for(int j=0;j<=n;j++)if(i^j)xx.x[0]=xx.x[0]*fpow(i-j)%Mod;
		for(int j=0;j<=n;j++)if(j^i){yy.x[0]=Mod-j;yy.x[1]=1;xx=xx*yy;}
		a=a+xx;xx.clear();
	}
}
ll f(int k1,int k2,ll a,ll b,ll c,ll n,int d=0){
	if(~F[k1][k2][d]) return F[k1][k2][d];
	ll ans=0;
	if(!a) ans=B[k1](n,k1)*fpow(b/c,k2)%Mod;
	else if(!k2) ans=B[k1](n,k1);
	else if(a>=c||b>=c){
		int x=a/c,y=b/c;a%=c;b%=c;
		for(ll i=0,X=1;i<=k2;i++,X=(X*x)%Mod){
			for(ll j=0,Y=X;i+j<=k2;j++,Y=Y*y%Mod){
				ans=(ans+f(k1+i,k2-i-j,a,b,c,n,d+1)*C[k2][i]%Mod*C[k2-i][j]%Mod*Y%Mod)%Mod;
			}
		}
	}else{
		int m=(a*n+b)/c;--m;
		ans=A[k2](m,k2);
		ans=ans*B[k1](n,k1)%Mod;
		for(int j=0;j<k2;j++)for(int i=0;i<=k1+1;i++){
			ans=(ans-f(j,i,c,c-b-1,a,m,d+1)*C[k2][j]%Mod*B[k1].x[i]%Mod)%Mod;
		}
	}
	if(ans<0)(ans%=Mod)+=Mod;ans%=Mod;
	return F[k1][k2][d]=ans;
}
void init(){
	C[0][0]=1;
	for(int i=1;i<=10;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
	for(int i=0;i<=10;i++){
		if(i)y[0]=1;
		for(int j=1;j<=i+1;j++){
			y[j]=(y[j-1]+fpow(j+1,i)-fpow(j,i))%Mod;
			if(y[j]<0)y[j]+=Mod;
		}
		calc(A[i],i+1);
		if(!i)y[0]=1;else y[0]=0;
		for(int j=1;j<=i+1;j++)y[j]=(y[j-1]+fpow(j,i))%Mod;
		calc(B[i],i+1);
	}
}
int T,a,b,c,n,k1,k2;
int main(){
	init();
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d%d%d%d",&n,&a,&b,&c,&k1,&k2);
		memset(F,-1,sizeof(F));
		printf("%d\n",f(k1,k2,a,b,c,n));
	}
	return 0;
} 
