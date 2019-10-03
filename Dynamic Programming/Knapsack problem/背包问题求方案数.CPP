#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e3+50;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int N , V , v, w;
int cnt[maxn],f[maxn];
int main()
{
	cin >> N >> V;
	fill(cnt, cnt + V+1,1);
	for(int i = 1; i <= N;i++){
		cin >> v >> w;
		for(int j = V;j >= v;j--){
			int val = f[j - v] + w;
			if(val > f[j]){
				f[j] = val;
				cnt[j] = cnt[j - v];
			}else if(val == f[j]){
				cnt[j] = (cnt[j] + cnt[j - v])%mod;
			}
		}
	}
	cout << cnt[V] <<endl;
}
