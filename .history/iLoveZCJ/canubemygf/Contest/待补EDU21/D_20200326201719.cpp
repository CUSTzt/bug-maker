// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1), sum(n + 1);
    map<ll, int> MP;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        MP[sum[i]] = 1;
    }
    ll p = sum[n];
    if (p & 1) {
        return cout << "NO", 0;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] > p / 2) return cout << "NO", 0;
    for(int i =1; i <=n; i++)
    if(sum[i-1]<= p/2+a[i]&&MP[p/2+a[i]]==1)return cout <<"YES",0;
    for(int i = 1; i<=n; i++){
        if(sum[i-1]>=)
    }
    return 0;
}