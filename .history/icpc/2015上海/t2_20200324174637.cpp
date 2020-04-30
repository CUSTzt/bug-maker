// She is Pretty pretty!
// @DateTime:    2020-03-24 17:37:42
// @FileName:    C:\Users\Answer Accepted\Desktop\Lerica\icpc\2015上海\t2.cpp
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
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int ex, ey;
        cin >> ex >> ey;
        // x , y  z=lcm(x,y);
        int g = __gcd(ex, ey);
        if(ex < ey)
        int ans;
        cout << "Case #" << cs << ": " << ans << endl;
    }
    return 0;
}