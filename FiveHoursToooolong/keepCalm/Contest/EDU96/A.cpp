// can i beat Mod Love? 
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
typedef long long ll;
ll bin(ll x, ll n, ll MOD) {ll ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = acos(-1.0);
constexpr ll mod = 1e9+7;
constexpr int maxn = 1e6+100; // remember to calculate.

void up(){
	int n , x = 0, y  = 0, z = 0;
	cin >> n ;
	if(n %  3==0){
		x = n/3;
	}else if(n % 3 == 1){
		x = (n-7) / 3;
		z = 1;
	}else{
		x = (n-5)/3;
		y = 1;
	}
	if(x < 0|| y < 0|| z < 0){
		cout << -1 << endl;
	}else{
		cout << x << ' ' << y << " " << z << endl;
	}
}
int main()
{
	int _;
	cin >> _;
	while(_--){
		up();
	}	   
	return 0;
}