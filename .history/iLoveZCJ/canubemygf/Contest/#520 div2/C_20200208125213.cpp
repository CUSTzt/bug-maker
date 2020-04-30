/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-08 12:41:50
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
int a,b,i,m,t=1,g[10];
int main(){
    cin>>a;
    while(a){
        b=a%10;
        for(i=9;i>9-b;i--)
            g[i]+=t;
        if(b>m) m=b;
        t*=10;
        a/=10;
    }
    cout<<m<<endl;
    for(i=0;i<10;i++){
        if(g[i])
            cout<<g[i]<<" ";
    }
    return 0;
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/