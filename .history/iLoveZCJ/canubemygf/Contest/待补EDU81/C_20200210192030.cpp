/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-10 19:20:28
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int main()
{
    string s,t;
	int T;
	cin>>T;
	while(T--){
		cin>>s>>t;
		for(int i=0;i<26;i++) v[i].clear();//初始化
		for(int i=0;i<s.size();i++) v[s[i]-'a'].push_back(i);
		int cnt=1,k=0;
		for(int i=0;i<t.size();i++){
			int x=s[i]-'a';
			int l=lower_bound(v[x].begin(),v[x].end(),k)-v[x].begin();
			if(!v[x].size()){
				cnt=-1;
				break;
			}
			else if(l==v[x].size()) k=0,cnt++,i--;
			else k=v[x][l]+1;
		}
		cout<<cnt<<endl;
	}
————————————————
版权声明：本文为CSDN博主「陆小萌」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Meulsama/article/details/104120603
    
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/