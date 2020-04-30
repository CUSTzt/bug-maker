// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , m ;
bool check(int n , int m){
    ll s = 0;
    for(int i = n-2;i >= 1;i-=2){
        s+=i;
        cout <<"i === " << i << endl;
    }
    if(s < m)return true;
    return false;
}
int main()
{
    cin >> n >> m;
    if(check(n , m)){
        return cout << -1 ,0;
    }
    cout <<'s';
    return 0;
}