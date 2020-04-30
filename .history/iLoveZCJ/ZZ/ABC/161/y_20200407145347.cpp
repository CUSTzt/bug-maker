#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N]; 
int main(){
	int n,k,c;
	string s;
	cin>>n>>k>>c>>s;
	for(int i=0,id=0;i<n;i++) if(s[i]=='o') a[id++]=i,i+=c;
	for(int i=n-1,id=k-1;i>=0&&id>=0;i--) if(s[i]=='o') b[id--]=i,i-=c;//这id要从k-1开始因为最多有k天工作. 
	for(int i=0;i<k;i++) if(a[i]==b[i]) cout<<a[i]+1<<endl;//由于开始下标为0,所以要加1 
	return 0; 
}
