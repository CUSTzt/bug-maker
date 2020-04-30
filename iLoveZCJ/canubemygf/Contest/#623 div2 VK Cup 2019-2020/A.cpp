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
int main()
{
    //cout << maxn << endl;
    int t;
    cin>>t;
    while(t--){
        int a,b,x,y;
        scanf("%d%d%d%d",&a,&b,&x,&y);
        int ans=max(max((x)*b,(y)*a),max((a-x-1)*b,(b-y-1)*a));
        cout<<ans<<endl;
    }
    return 0;
}