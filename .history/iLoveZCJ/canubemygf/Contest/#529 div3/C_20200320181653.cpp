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
    int n , k;
    cin >> n >>k;
    int cnt = __builtin_popcount(n);
    if(cnt > k || (( k - cnt) & 1)){
        return cout << "NO", 0;
    }
    
    return 0;
}