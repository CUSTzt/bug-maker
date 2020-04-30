// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
mt19937 RNG(std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n)
{
    return RNG() % n;
}
int n;
ll a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    random_shuffle(a,a+n,rnd);
    
    return 0;
}