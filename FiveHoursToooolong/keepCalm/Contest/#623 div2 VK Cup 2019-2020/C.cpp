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
const int N=2e2+10,M=N*40;
int n;
int a[N];
bool vis[N];
int ans[N];
int main()
{
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]=1;
        }
        set<int>s;
        for(int i=1;i<=n*2;i++){
            if(!vis[i])s.insert(i);
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            auto k=s.lower_bound(a[i]);
            if(k==s.end()){
                printf("-1\n");
                flag=0;
                break;
            }
            ans[i*2-1]=a[i];
            ans[i*2]=*k;
            s.erase(*k);
        }
        if(flag){
            for(int i=1;i<=n*2;i++)printf("%d ",ans[i]);printf("\n");
        }
    }
    return 0;
}