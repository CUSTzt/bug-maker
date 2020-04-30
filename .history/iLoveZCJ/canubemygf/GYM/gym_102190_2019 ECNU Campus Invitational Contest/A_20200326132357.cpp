// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int a, b, c, ans;
    if (n == 3) {
        a = s[0] - '0';
        b = 12+s[1] - '0';
        c = s[2] - '0';
    } else if (n == 4) {
        a = 10 * (s[0] - '0') + (s[1] - '0');
        b = 12 + 10 * (s[2] - '0');
        c = s[3] - '0';
        if (a < 2 || a > 11 || b < 14 || b > 23) {
            a = 10 * (s[0] - '0');
            b = 12 + 10 * (s[1] - '0') + (s[2] - '0');
        }
    } else {
        a = 10 * (s[0] - '0') + (s[1] - '0');
        b = 12 + 10 * (s[2] - '0') + (s[3] - '0');
        c = s[4] - '0';
    }
    ans = (b - a) * c;
    cout << ans << endl;
}