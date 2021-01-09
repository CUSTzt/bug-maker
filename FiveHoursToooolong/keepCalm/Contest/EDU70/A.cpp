/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-09 14:28:46
 * @Description: You build it, You run it.
 ***********************************************/
#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e6 + 10;
#define eps 1e-8
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int lens = s.length();
        int lent = t.length();
        int cnt = 0;
        for (int i = lent - 1; i >= 0; i--) {
            if (t[i] != '0') break;
            cnt++;
        }
        int ans = 0;
        for (int i = lens - cnt - 1; i >= 0; i--) {
            if (s[i] != '0') break;
            ans++;
        }
        cout << ans << endl;
    }
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
 ****************************************************/