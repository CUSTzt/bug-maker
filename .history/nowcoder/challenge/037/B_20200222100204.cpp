#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-8;
const int N=1e6+10,M=N*40,mod=1e9+7;
struct mat{
    LL c[16][16];
    mat operator*(const mat &t)const{
        mat z;
        memset(z.c,0,sizeof(z.c));
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                for(int k=0;k<16;k++){
                    z.c[i][j]=(z.c[i][j]+c[i][k]*t.c[k][j]%mod)%mod;
                }
            }
        }
        return z;
    }
};
mat mul;
int check(int x){
    int re=0;
    while(x){
        re+=x&1;
        x>>=1;
    }
    return re;
}
int main()
{
    LL n;
    cin>>n;
    mat ans;
    memset(ans.c,0,sizeof(ans.c));
    for(int i=0;i<16;i++)ans.c[i][i]=1;
    mat x;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            if(check(i^j)==1)x.c[i][j]=1;
            else x.c[i][j]=0;
        }
    }
    while(n){
        if(n&1)ans=ans*x;
        x=x*x;
        n>>=1;
    }
    cout<<ans.c[0][3];
    return 0;
}