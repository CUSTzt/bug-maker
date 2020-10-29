#include<iostream>

using namespace std;
using ll = long long;
int main(){
    ll a, b , c, d, e, f;
    while(cin >> a >> b >> c >> d >> e >> f){
        cout << abs(a * d + c * f + e * b - c * b - e * d - a * f) * 11ll << endl;
    }

}