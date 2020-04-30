// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, b;
    cin >> a >>b;
    ll fenzi ;
    if(a >= b){
        fenzi = (2*b-a)*a/2;
    }
    else fenzi = a*b/2;
    ll fenmu = a*b;
    ll g = gcd(fenzi,fenmu);
    cout << fenzi/g <<" " <<fenmu/g;
    return 0;
}