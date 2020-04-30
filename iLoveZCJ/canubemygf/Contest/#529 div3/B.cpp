// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    sort(a , a+n);
    cout << min(a[n-1] - a[1], a[n-2] - a[0]);
    return 0;
}