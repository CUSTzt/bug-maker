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
    ll a , b , x , n , y;
    cin >> a >> b >> x >> y >> n;
    ll q1 = max(x , a-n), q2 = max(y , b - (n-(a-q1)));
    ll q3 = max(y , b-n), q4 = max(x, a - (n-(b-q3)));
    cout << min(q1 * q2 , q3 * q4) <<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}