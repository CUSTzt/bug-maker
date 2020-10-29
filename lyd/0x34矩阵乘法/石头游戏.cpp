#include<bits/stdc++.h>
using namespace std;
#define go(i,a,b) for(int i=a;i<=b;++i)
#define int long long
const int inf=0x3f3f3f3f,N=12;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,m,t,act,p,c[N][N];
char a[N][N],op[N][N];
mat A,B[65],C;
inline int num(int i,int j){ return (i-1)*m+j; }
inline void mul(mat &A,const mat &B){
    mat ans(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();++i)
        for(int j=0;j<B[0].size();++j)
            for(int k=0;k<B.size();++k)
                ans[i][j]=ans[i][j]+A[i][k]*B[k][j];
    A=ans;
}
signed main(){
    cin>>n>>m>>t>>act;
    go(i,1,n){
        scanf("%s",a[i]+1);
        go(j,1,m) a[i][j]-='0';
    }
    for(int i=0;i<act;++i) scanf("%s",op[i]);
    p=n*m+1;
    go(i,1,60) B[i].resize(p,vec(p));
    int x,y;
    go(k,1,60){
        go(i,1,n)
            go(j,1,m){
                x=a[i][j],y=c[i][j];
                if(isdigit(op[x][y])){
                    B[k][0][num(i,j)]=op[x][y]-'0';
                    B[k][num(i,j)][num(i,j)]=1;
                }
                else if(op[x][y]=='N'&&i>1) B[k][num(i,j)][num(i-1,j)]=1;
                else if(op[x][y]=='S'&&i<n) B[k][num(i,j)][num(i+1,j)]=1;
                else if(op[x][y]=='W'&&j>1) B[k][num(i,j)][num(i,j-1)]=1;
                else if(op[x][y]=='E'&&j<m) B[k][num(i,j)][num(i,j+1)]=1;
                c[i][j]=(y+1)%strlen(op[x]);
            }
        B[k][0][0]=1;
    }
    C=B[1];
    go(i,2,60) mul(C,B[i]);
    A.resize(1,vec(p));A[0][0]=1;
    int ans=0,w=t/60;
    for(;w;w>>=1){
        if(w&1) mul(A,C);
        mul(C,C);
    }
    w=t%60;
    go(i,1,w) mul(A,B[i]);
    for(int i=0;i<p;++i) ans=max(ans,A[0][i]);
    cout<<ans;
    return 0;
}
