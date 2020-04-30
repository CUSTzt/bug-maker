#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,h1,h2;
int main()
{
	cin>>a>>b>>h1>>h2;
	h1+=h2;
	if(!(a&1))a/=2;
	else if(!(b&1))b/=2;
	else if(!(h1&1))h1/=2;
	cout<<a*b*h1<<endl;
	return 0;
}
