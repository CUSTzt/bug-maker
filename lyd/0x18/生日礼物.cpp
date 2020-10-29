#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int a[100100],l[100100],r[100100];
bool st[100100];
priority_queue<pii,vector<pii>,greater<pii> > q;
void Remove(int p){
    l[r[p]]=l[p]; r[l[p]]=r[p];st[p]=1;
}
int main()
{
    int n,m,k=0; cin>>n>>m;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(!x) continue;
        if(!k||(ll)a[k]*x<0) a[++k]=x;      //连续的正的存一起，负的存一起
        else a[k]+=x;
    }
    int ans=0,cnt=0;
    for(int i=1;i<=k;i++){
        l[i]=i-1,r[i]=i+1;
        q.push({abs(a[i]),i});
        if(a[i]>0) ans+=a[i],cnt++;     //判断有几段正的
    }
    while(cnt>m){       //删掉正的或者添加负的连起来
        auto it=q.top();
        q.pop();
        int x=it.fi,y=it.se;
        if(st[y]) continue;
        if(l[y]!=0&&r[y]!=k+1||a[y]>0) {
            a[y]+=a[l[y]]+a[r[y]];
            int lefi=l[y], right=r[y];
            ans-=x;
            q.push({abs(a[y]),y});
            Remove(lefi);
            Remove(right);
            cnt--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
