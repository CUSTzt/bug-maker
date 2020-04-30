/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-13 22:25:49
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
    #define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=1e6+10,ha=26;
int n,m,k;
struct node{
    int f;
    int len;
    char a[4];
};
vector<node>v;
void solve(){
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++){
        node &x=v[i];
        printf("%d ",x.f);
        for(int j=0;j<x.len;j++)printf("%c",x.a[j]);
        printf("\n");
    }
}
int main()
{
    cin>>n>>m>>k;
    if(4*n*m-2*n-2*m<k){
        cout<<"NO"<<endl;return 0;
    }
    printf("YES\n");
    if(m==1){
        if(k<n){
            printf("1\n");
            printf("%d D\n",k);
        }
        else{
            printf("2\n");
            printf("%d D\n",n-1);
            printf("%d U\n",k-n+1);
        }
        return 0;
    }
    if(n==1){
        if(k<m){
            printf("1\n");
            printf("%d R\n",k);
        }
        else{
            printf("2\n");
            printf("%d R\n",m-1);
            printf("%d L\n",k-m+1);
        }
        return 0;
    }
    node x;
    for(int i=1,kk;i<n;i++){
        if(m>2){
            kk=(m-2);
            if(kk*3>=k){
                kk=k/3;
                x.len=3;
                x.f=kk;
                x.a[0]='R';
                x.a[1]='D';
                x.a[2]='U';
                if(x.f>0)v.PB(x);
                k-=kk*3;
                //cout<<k<<endl;
                if(k==0){
                    solve();
                    return 0;
                }
                x.len=k;
                x.f=1;
                x.a[0]='R';
                if(x.len==2)x.a[1]='D';
                v.PB(x);
                solve();
                return 0;
            }
            k-=kk*3;//cout<<k<<endl;
            x.f=kk;
            x.len=3;
            x.a[0]='R';
            x.a[1]='D';
            x.a[2]='U';
            v.PB(x);
        }

        if(i>1){
            x.len=3;
            x.a[0]='R';
            x.a[1]='U';
            x.a[2]='D';
            x.f=1;
            if(k<=3){
                x.len=k;v.PB(x);
                solve();
                return 0;
            }
            k-=x.len;//cout<<k<<endl;
            v.PB(x);
        }
        else{
            x.len=1;
            x.a[0]='R';
            x.f=1;
            v.PB(x);
            if(k<=1){
                k=0;
                solve();
                return 0;
            }
            k-=x.len;//cout<<k<<endl;
        }
        x.f=m-1;
        x.len=1;
        x.a[0]='L';
        if(k<=m-1){
            x.f=k;
            v.PB(x);
            solve();
            return 0;
        }

        k-=x.f;
//cout<<k<<endl;
        v.PB(x);
        x.f=1;
        x.len=1;
        x.a[0]='D';
        if(k<=1){
            v.PB(x);
            k=0;
            solve();
            return 0;
        }
        k-=1;//cout<<k<<endl;
        v.PB(x);
    }
    //cout<<k<<endl;
    if(k==0){
        solve();
        return 0;
    }
    x.f=m-1;
    x.len=1;
    x.a[0]='R';
    if(k<=m-1){
        x.f=k;
        v.PB(x);
        solve();
        return 0;
    }
    v.PB(x);k-=m-1;
    //cout<<k<<endl;
    x.f=1;
    x.len=2;
    x.a[0]='U';
    x.a[1]='D';
    if(k<=2){
        x.len=k;
        v.PB(x);
        solve();
        return 0;
    }
    v.PB(x);
    k-=x.len;
    x.f=m-1;
    x.len=1;
    x.a[0]='L';
    if(k<=m-1){
        x.f=k;
        v.PB(x);
        solve();
        return 0;
    }
    v.PB(x);k-=m-1;//cout<<k<<endl;
    x.f=k;
    x.len=1;
    x.a[0]='U';
    v.PB(x);
    solve();
}
    
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/