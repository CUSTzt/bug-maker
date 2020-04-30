#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e6+10;
using namespace std;
int main()
{
	int n, d, e;
	cin >> n>>d>>e;
	int k1 = n/d;
	int k2 = n/(e*5);
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= k1;i++){
		ans = min(ans , (n-i*d)%(5*e));
	}
	for(int i = 0; i <= k2;i++){
		ans = min(ans, (n-i*e*5)%(d));
	}
	cout << ans <<endl;
 
}