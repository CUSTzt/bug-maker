#include<bits/stdc++.h>
using namespace std;
#define int long long 
int DateToInt (int m, int d, int y){  
  return 
    1461 * (y + 4800 + (m - 14) / 12) / 4 +
    367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 
    3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 + 
    d - 32075;
}
int32_t main()
{
    int a,b,c,d,e,f;
    scanf("%04d-%02d-%02d %02d:%02d:%02d",&a,&b,&c,&d,&e,&f);
    int pp1 ,pp2;
    pp1=DateToInt(b,c,a)*86400+d*3600+e*60+f;
        scanf("%04d-%02d-%02d %02d:%02d:%02d",&a,&b,&c,&d,&e,&f);

    pp2=DateToInt(b,c,a)*86400+d*3600+e*60+f;
    cout << pp2-pp1);
    return 0;
}