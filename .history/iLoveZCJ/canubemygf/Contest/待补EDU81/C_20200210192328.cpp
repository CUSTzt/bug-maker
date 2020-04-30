#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 5;

vector<int>v[26];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
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
	return 0;
}
