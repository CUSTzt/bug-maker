 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-16 16:51:34
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
 //Q题
 //NIM博弈 基础题
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[maxn];
int main()
{
    close;
    while(1)
    {
        int p;
        cin>>p;
        if(p==0)break;
        int sum=0;
        for(int i=0;i<p;i++){
            cin>>a[i];
            sum^=a[i];
        }
        if(sum==0)cout<<"No"<<endl;
        else {
            cout<<"Yes"<<endl;
            for(int i=0;i<p;i++){
                int k=sum^a[i];
                if(k<a[i])cout<<a[i]<<" "<<k<<endl;//k比[i]小说明可以实现
            }
        }
    }
}