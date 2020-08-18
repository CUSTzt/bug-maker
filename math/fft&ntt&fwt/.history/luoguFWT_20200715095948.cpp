#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define REV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void FWT(int a[],int n, int op)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                if(op == 1)a[i+j]=(x+y)%MOD,a[i+j+d]=(x-y+MOD)%MOD;     
                //and:
                if(op == 2)a[i+j]=x+y;    
                //or:
                if(op == 3)a[i+j+d]=x+y;    
            }    
}    
    
void UFWT(int a[],int n, int op)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                if(op == 1)a[i+j]=1LL*(x+y)*REV%MOD,a[i+j+d]=(1LL*(x-y)*REV%MOD+MOD)%MOD;      
                //and:
                if(op == 2)a[i+j]=x-y;    
                //or:
                if(op == 3)a[i+j+d]=y-x;    
            }    
}    
void solve(int a[],int b[],int n, int op)    
{    
    FWT(a,n);    
    FWT(b,n);    
    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%MOD;    
    UFWT(a,n);    
}   
int main()
{
    return 0;
}
