// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int t , n , a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>  t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int fl = 0;
        for(int i = 0; i < n-2;i++){
            if(lower_bound(a+i,a+n,a[i])!=upper_bound(a+i,a+n,a[i]) && ){fl = 1;break;}
            
        }
        puts((!fl)?"NO":"YES");
    }
    return 0;
}