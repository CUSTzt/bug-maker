// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
ll l1, l2, r1, r2, k;
int main()
{
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    if(l2 > r1 || l1 > r2){
        return cout << 0 ,0;
    }
    ll lll = max(l1, l2);
    ll rrr = min(r1,r2);
    ll ans = rrr-lll+1-[k<=];
    return 0;
}