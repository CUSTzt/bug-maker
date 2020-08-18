#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int main()
{
	int a , b , c;
	cin >> a >> b >> c;
	if(a <= b+c){
        cout << "NO\n";
        exit(0);
    }else cout << "YES\n";
    if(a == 1 && b == 0 && c == 0){
        cout << 0 << endl;
    }else {
        cout << c+b+ (c+b+1) <<endl;
    }
}