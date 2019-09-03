 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-18 19:36:30
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 0x7f7f7f7f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
set<pair<int ,int > >s;
int main()
{
	int n,a;
	cin >> n >> a;
	s.insert(make_pair(a,1));
	for(int i =2;i <= n; i++){
		cin>>a;
		s.insert(make_pair(a,i));
		//set<pair <int ,int > >::iterator it =s.find(make_pair(a,i));
		auto it=s.find(make_pair(a,i));
		pair<int ,int  >ans;
		ans.first = INF;
		if(++it != s.end())
		ans=make_pair((*it).first-a,(*it).second);
		it= s.find(make_pair(a,i));
		if(it-- !=s.begin()&&ans.first >=a - (*it).first)
			ans=make_pair(a-(*it).first,(*it).second);
		cout<<ans.first<<" "<<ans.second<<endl;
	}
	exit(0);
}
