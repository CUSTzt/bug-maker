#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define ULL unsigned long long
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-10;
const int maxn=1e6+100;
const int N=5e3+10,M=N*40;
int n, a[maxn],b[maxn];//,c[maxn];
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <=n ; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <=n ; i++){
        scanf("%d",&b[i]);
    }
    vector<int >c;
    for(int i = 1; i<= n; i++){
        c.PB(a[i]-b[i]);
    }
    sort(c.begin(),c.end());
    int si = c.size();
    long long ans=0;
    for(int i = 0; i < si;i++){
        vector<int>::iterator p=upper_bound(c.begin()+i+1,c.end(),-c[i]);
        if(p!=c.end()){
            ans+=c.end()-p;
        }
    }
    cout <<ans << endl;
}