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
    ll n , m , k , l ;
    cin >> n >> m >> k >> l ;
    if(n < m || n - k < 1 ){
        return puts("-1"),0;
    }
    ll res = (k+l) / m;
    if(res * m < k+l) 
    return 0;
}