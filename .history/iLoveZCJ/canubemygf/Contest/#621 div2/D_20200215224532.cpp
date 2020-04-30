#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=1e6+10,ha=26,mod=1e9+7;
const double pi=acos(-1),eps=1e-8;
int n;
char a[N];
int s[N];
int b[N];

void solve(){
    scanf("%d%s",&n,a+1);
    int k=n,cnt=0;
    for(int i=1;i<=n;i++)b[i]=0;
    for(int i=1;i<n;i++){
        cnt++;
        if(a[i]=='>')b[i]=k,k-=cnt,cnt=0;
    }
    //for(int i=1;i<=n;i++)printf("%d ",b[i]);printf("\n");
    b[n]=k;

    //cout<<1<<endl;
    for(int i=n-1;i>=1;i--){
        if(b[i]==0)b[i]=b[i+1]-1;
    }
    for(int i=1;i<=n;i++)printf("%d ",b[i]);printf("\n");

   for(int i=1;i<=n;i++)b[i]=0;
    k=n,cnt=0;
    for(int i=n-1;i>=1;i--){
        cnt++;
        if(a[i]=='<')b[i+1]=k,k-=cnt,cnt=0;
    }
    b[1]=k;
    for(int i=2;i<=n;i++){
        if(b[i]==0)b[i]=b[i-1]-1;
    }
    for(int i=1;i<=n;i++)printf("%d ",b[i]);printf("\n");
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}