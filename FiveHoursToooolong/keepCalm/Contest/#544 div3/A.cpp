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
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b , c, d;
    scanf("%02d:%02d",&a,&b);
    scanf("%02d:%02d",&c,&d);
    int t = ((a+c)*60+(b+d))/2;
    int ans1 = t /60,ans2=t%60;
    printf("%02d:%02d",ans1,ans2);
    return 0;
}