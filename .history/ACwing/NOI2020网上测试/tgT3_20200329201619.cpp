// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll n , m , a[N], sum;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i]*a[i];
	}
	sort(a+1, a+1+n);
	map<ll , ll> MP;
	for(int ks = 1; ks <= m; ks++){
		int k;
		cin >> k;
		if(k == 0){
			cout << sum << endl;
			continue;
		}
		ll g = gcd(n , k);
		if(MP.count(g)){
			cout << MP[g] <<endl;
			continue;
		}
		for(int i = 1; i <= g; i++){
			for(int j = 1; j <n/g;j++){
				ll zz = (i-1)*n/g
			}
		}
	}
    return 0;
}