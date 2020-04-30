a#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define ULL unsigned long long
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-10;
const int maxn=1<<17;
const int N=2e5+10,M=N*40;
int n;
struct node{
    LL p,t;
    bool operator<(const node&x)const{
        return p<x.p;
    }
}a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].p);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].t);
    }
    sort(a+1,a+1+n);
    LL now=0;
    LL cost=0;
    priority_queue<LL>q;
    LL ans=0;
    for(int i=1;i<=n;i++){
 
        if(a[i].p!=now){
            LL pos=now;
            while(pos<a[i].p&&!q.empty()){
                LL x=q.top();
                q.pop();
                cost-=x;
                ans+=(pos-now)*x;
                pos++;
            }
            ans+=(a[i].p-now)*cost;
            now=a[i].p;
        }
        cost+=a[i].t;
        q.push(a[i].t);
        //cout<<i<<' '<<' '<<a[i].p<<' '<<a[i].t<<' '<<ans<<endl;
 
    }
    LL pos=now;
    while(!q.empty()){
        int x=q.top();
        q.pop();
        ans+=(pos-now)*x;
        pos++;
    }
    printf("%lld\n",ans);
    return 0;
}