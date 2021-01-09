// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

void up() {
    int a, b , c;
    cin >> a >> b >> c;
    int ans = 0;
    while(a <= c && b <= c){
        if(a < b)swap( a , b);
        b+= a;
        ans++;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}