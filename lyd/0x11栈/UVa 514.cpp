 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-22 14:28:59
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e3+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n,target[maxn];
int main()
{
	while(cin>>n&&n!=0){
		stack<int >s;
		int A = 1, B = 1;
		for(int i = 1;i <= n;i++)
			cin>>target[i];
		int ok = 1;
		while(B <= n){
			if(A == target[B]){A++;B++;}
			else if(!s.empty()&&s.top() == target[B]){s.pop();B++;}
			else if(A <= n)s.push(A++);
			else {ok = 0;break;}
		}
		cout<<(ok?"Yes":"No")<<endl;
	}
}