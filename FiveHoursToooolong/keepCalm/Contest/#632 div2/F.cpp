
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
    int n ;
    cin >> n;
    vector<int> ans(n+1, 1);
    for(int i = 2; i <= n; i++){
        for(int j = i * 2; j <= n; j += i){
            ans[j] = i;
        }
    }
    sort(ans.begin() , ans.end());
    for(int i = 2; i <= n; i++){
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}