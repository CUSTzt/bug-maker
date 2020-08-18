#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=1e5+10;
const double eps=1e-7;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
int n,m;
double t1,t2,V;
// int x1[SIZE],y11[SIZE],x2[SIZE],y2[SIZE];
pair<int , int > aa[SIZE], bb[SIZE];
double d[55][55],c[55];
int head[SIZE],ver[SIZE],nxt[SIZE],tot;
int match[SIZE],v[SIZE];
void add(int x,int y){
    ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
bool dfs(int x){
    for(int i=head[x];i;i=nxt[i]){
        int y=ver[i];
        if(!v[y]){
            v[y]=1;
            if(!match[y]||dfs(match[y])){
                match[y]=x;
                return true;
            }
        }
    }
    return false;
}
bool check(double x){
    memset(head,0,sizeof(head));
    memset(match,0,sizeof(match));tot=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++){
                if(c[k]+d[i][j]<=x)add(i,j*m+k);
                else break;
            }
    for(int i=1;i<=m;i++){
        memset(v,0,sizeof(v));
        if(!dfs(i))return false;
    }
    return true;
}
int main(){
    scanf("%d%d%lf%lf%lf",&n,&m,&t1,&t2,&V);t1=(double)t1/60;
    for(int i=1;i<=m;i++)scanf("%d%d",&aa[i].first,&aa[i].second);
    for(int i=1;i<=n;i++)scanf("%d%d",&bb[i].first,&bb[i].second);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(double)sqrt((double)(aa[i].first-bb[j].first)*(aa[i].first-bb[j].first)+(double)(aa[i].second-bb[j].second)*(aa[i].second-bb[j].second))/V;
    for(int i=1;i<=m;i++)c[i]=t1*i+t2*(i-1);
    double l=t1,r=1e5,mid;
    while(r-l>eps){
        mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    printf("%.6lf",l);
    return 0;
}