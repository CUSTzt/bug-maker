// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int n, k, c;
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> c >> s;
    int cnt = 0;
    vector<int> a(n + 10, 0), b(n + 10, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            a[cnt++] = i;
            i += c;
        }
    }
    int tp = k - 1;
    for (int i = n - 1; i >= 0 && tp >= 0; i--) {
        if(s[i] == 'o'){
            b[c]
        }
    }
    return 0;
}