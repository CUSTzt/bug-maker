// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , m;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    map<int, int> zz;
    for(int ks = 0; ks < n; ks++){
        string s;
        cin >> s;
        int n = s.size();
        int a = -1, b = -1;
        for(int i = 0; i <= n; i++){
            if(s[i] == 'G') a = i;
        }
    }
    return 0;
}