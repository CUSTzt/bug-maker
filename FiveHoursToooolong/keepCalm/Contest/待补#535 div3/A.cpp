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
    int a, b , c , d;
    cin>> a>> b >> c >> d;
    if(a!=c)cout << a << " " << c << endl;
    else if(a!=d)cout << a << " " << d << endl;
    else cout << b << " " << d << endl;

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}