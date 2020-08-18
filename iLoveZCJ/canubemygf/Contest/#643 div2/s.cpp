// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+100;
int n , sum[N] , a[N];
int limit ;
__int128 b[20];
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    map<int , int > mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] += a[i]+sum[i-1];
        mp[sum[i]]++;
    }
    int ans = -1;
    b[0] = 1;
    for(int i = 1; i <=5 ; i++){
        b[i] =(__int128) b[0] * 520;
        limit = i;
        if(b[i] > sum[n])break;
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < limit; j++){
            if(mp.count(sum[i]+b[j])) ans = max(ans, j);
        }
    }
    cout << ans << endl;
    return 0;
}