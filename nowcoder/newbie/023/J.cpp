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
    int n;
    cin >> n;
    vector<int >a;
    for(int i = 0; i <n;i++){
        int x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    cout << a[n-1] -a[0];
}