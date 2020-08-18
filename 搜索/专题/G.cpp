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
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (!a && !b && !c) return 0;
        if (b == c) {
            cout << "1" << endl;
            continue;
        }
        // if(a & 1){
        //     cout << "NO" << endl;
        //     continue;
        // }
        int g = __gcd(b, c);
        a /= g;
        if (a & 1)
            cout << "NO" << endl;
        else
            cout << (a - 1) << endl;
    }
    return 0;
}