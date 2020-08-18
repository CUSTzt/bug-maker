#include<bits/stdc++.h>
const int N = 3e5+5;
using namespace std;
int f[N],r[N];
void init(int size){for(int i=0;i<=size;i++) f[i]=i;}
int find(int x){while(f[x]!=x) x=f[x]; return x;}
void setroot(int x){if(f[x]!=x) setroot(f[x]); f[x]=f[f[x]]=x;}
void link(int a,int b){setroot(a);f[a]=b;}
void cut(int a,int b){setroot(a);f[b]=b;}
pair<int,int>e[N];
int main(){
    int x,y,t,q,m,n;
    scanf("%d",&t);
    while(t--) {
        int las=0;
        scanf("%d%d%d",&n,&m,&q);
        init(n);
        for(int i=1;i<=m;i++) {r[i]=0;scanf("%d%d",&x,&y);e[i]={x,y};}
        int pos=0;
        for(int i=1;i<=m;i++) {
            while(pos<m&&find(e[pos+1].first)!=find(e[pos+1].second)) {
                link(e[pos+1].first,e[pos+1].second);pos++;
            }
            if(pos==m) r[i]=1e9;
            else r[i]=pos+1;
            cut(e[i].first,e[i].second);
        }
        while(q--){
            scanf("%d%d",&x,&y);
            x=(x^las)%m+1;
            y=(y^las)%m+1;
            if(x>y) swap(x,y);
            if(r[x]>y) puts("No"),las=0;
            else puts("Yes"),las=1;
        }
    }
    return 0;
}