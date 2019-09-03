 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-15 10:22:31
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
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
stack <int >s1,s2;
ll f[maxn+10],sum[maxn+10];
int main()
{
	close;
	int kk;
	while(cin>>kk)
	{
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		while( !s1.empty())s1.pop();
        while( !s2.empty())s2.pop();
		int pa=0;
		f[0]=-10300;
		for(int i=0;i<kk;i++)
		{
			char a;
			cin>>a;
			//cout<<"kkkk====="<<i<<endl;
            //f[0]=-10300;
			if(a=='I'){
				int t;
				cin>>t;
				pa++;
				s1.push(t);
				sum[pa]=sum[pa-1]+t;
				f[pa]=max(f[pa-1],sum[pa]);
			}
			if(a=='D'){
				s1.pop();
				pa--;
			}
			if(a=='L'){
				int k;
				if(!s1.empty()){
				k=s1.top();
				s1.pop();
				pa--;
				s2.push(k);}
			}
			if(a=='R'){
				int k;
				if(!s2.empty()){
				k=s2.top();
				s2.pop();
				pa++;
				s1.push(k);
				sum[pa]=sum[pa-1]+k;
				f[pa]=max(f[pa-1],sum[pa]);}
			}
			if(a=='Q'){
				int q;
				cin>>q;
				cout<<f[q]<<endl;
			}
		}
	}
}
