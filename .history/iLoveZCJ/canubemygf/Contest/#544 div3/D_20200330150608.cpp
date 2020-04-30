// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<double , int > mp1,  mp2;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    int zero = 0,pt = 0;
    for(int i = i = 1; i <= n; i++){
        if(a[i]==0&&b[i]==0){
            pt++;
        }
    }
    int mx
    cout << mx + pt;
    return 0;
}