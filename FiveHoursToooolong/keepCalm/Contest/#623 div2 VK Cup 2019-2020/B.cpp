#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define ULL unsigned long long
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-10;
const int maxn=1<<17;
const int N=1e6+10,M=N*40;
int n;
char s[N];
LL ans[N];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,p;
        scanf("%d%d%d",&a,&b,&p);
        scanf("%s",s+1);
        n=strlen(s+1);
        ans[n]=0;
        s[n]='c';
        int mn=n;
        for(int i=n-1;i>=1;i--){
            if(s[i]!=s[i+1]){
                if(s[i]=='A')ans[i]=ans[i+1]+a;
                else ans[i]=ans[i+1]+b;
            }
            else ans[i]=ans[i+1];
            if(ans[i]<=p)mn=i;
        }
        //for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
        printf("%d\n",mn);
    }
    return 0;
}