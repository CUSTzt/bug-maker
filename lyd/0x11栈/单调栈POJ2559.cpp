 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-15 15:58:25
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n;
ll a[100086],s[100086],w[100086];
int main()
{
    close;
	while(cin>>n&&n!=0)
	{
		ll ans=0,p=0;
		for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        a[n]=0;
        for(int i= 0;i<=n;i++)
        {
            if(a[i]>s[p])s[++p]=a[i],w[p]=1;
            else {
                ll width=0;
                while(s[p]>a[i])
                {
                    width+=w[p];
                    ans=max(ans,width*s[p]);
                    p--;
                }
                s[++p]=a[i],w[p]=width+1;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
