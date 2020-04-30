#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x) & (-x)
#define eps 1e-8
const int maxn = 1e6 + 10;
using namespace std;
int main() {
    int a, b, c;
    int ans = 0;
    cin >> a >> b >> c;
    for (int i = 0; i <= a; i++) {
        if (i <= a && c - i <= b && c - i >= 0) ans++;
    }
    cout << ans << endl;
}