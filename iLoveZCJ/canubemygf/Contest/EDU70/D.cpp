// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
ll s[N];
void up() {
    ll n;
    cin >> n;
    ll x = 1;
    while(x * (x+1) / 2 <= n){
        x++;
    }
    ll t = n - 1ll*(x-1)*x/2;
    cout << "133";
    for(int i = 0; i < t; i++){
        cout << '7';
    }
    for(int i = 3; i <= x; i++)cout << 3 ;
    cout << 7 << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}