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
    int k;
    cin >> k;
    string s , t;
    cin >> s >> t;
    int len = s.size();
    int chayi = 0, yiy = 0;
    for(int i =0; i < len; i++){
        chayi += (s[i] != t[i]), yiy += (s[i] == t[i]);
    }
    int ans = 0;
    if(yiy <= k){
        ans = len - (k-yiy);
    }else {
        ans = len-(yiy-k);
    }cout << ans << endl;
    return 0;
}