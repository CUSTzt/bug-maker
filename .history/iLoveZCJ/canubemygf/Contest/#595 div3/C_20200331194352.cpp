// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

void up() {
    ll n;
    cin >> n;
    vector<int > d(100,0);
    int  c = 0;
    while(n > 0){
        c++;
        d[c] = n % 3;
        n/=3;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}