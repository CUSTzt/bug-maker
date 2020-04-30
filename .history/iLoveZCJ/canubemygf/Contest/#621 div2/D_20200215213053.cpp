/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-15 21:09:14
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
string s[maxn];int a[maxn];
bool check(string s){
    
}
int main()
{
	int n , m ;
	cin >> n >> m;
	//set<string >st;
	int fl = 1;
		deque<string >ans;
	for(int i = 0;i < n; i++){
		cin >> s[i];
		string t = s[i];
		reverse(t.begin(),t.end());
		//cout << "t ==" << t << endl << "s == " << s[i] << endl;
		//if(strcmp(t.c_str(),s[i].c_str())==0&& !fl){ans.push_back(t);fl = 1;}
		if((strcmp(s[i].c_str(),t.c_str())==0)&& !fl){ans.push_back(t);fl = 1;}
		else {
			a[i] = 1;
		}
		//if(a[i] == 1)st.insert(s[i]);
	}
	for(int i = 0; i < n; i++){
		if(a[i] == 2){
			ans.push_back(s[i]);
			break;
		}
	}
	int cnt = 10;
	for(int i = 0; i < n; i++){
		string p = s[i];
		reverse(p.begin(),p.end());
		for(int j = i+1; j < n; j++){
			if(s[j] == p){
				ans.push_back(s[i]);
				ans.push_front(s[j]);
			}
		}
	}
	int size = ans.size()*m;
	cout << size << endl;
	while(!ans.empty()){
		cout << ans.front();
		ans.pop_front();
	}
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
