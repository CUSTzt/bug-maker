#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    set<ll> s;
    int m = sqrt(n + 0.5);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            ll nn = n;
            while(nn % i){
                nn /= i;
            }
            if(nn % i == 1)s.insert(i);
        }
    }
    
    cout << s.size();
    return 0;
}