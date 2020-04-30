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
int main()
{
	int t;
	cin >> t;
	while(t--){
		int x,  y , a , b;
		cin >> x >> y >> a >> b;
		cout <<  ((y-x)%(a+b)==0?(y-x)/(a+b):-1)<<endl;
	}
 
}