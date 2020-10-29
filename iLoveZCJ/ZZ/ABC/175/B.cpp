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
template <typename T>
void read(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
    return;
}
template <typename T>
void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &x : v) is >> x;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (!v.empty()) {
        os << v.front();
        for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
    }
    return os;
}

int main()
{
	close;
	int n;
	cin >> n;
	std::vector<int> a(n);
	cin >> a;
	int ans = 0;
	sort(a.begin(),a.end());
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				if(a[i] != a[j] && a[i] != a[k] && a[j] != a[k] && a[k] < a[i]+a[j] && a[i] > a[k]-a[j])ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
