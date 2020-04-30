#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define ULL unsigned long long
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-10;
const int maxn=1<<17;
const int N=5e3+10,M=N*40;
int t , a, b , c , ans , ansa, ansb , ansc;
int main()
{
    cin >> t;
    while(t--){
        ansa=0,ansb=0,ansc=0,ans =INF;
        for(int i = 1; i <= 11000; i++){
            for(int j = i ; j <= 11000;j+=i){
                for(int k = j ; k <= 11000; k +=j){
                    if(abs(a-i)+abs(b-j)+abs(c-k) <ans)
                    anns=abs(a-i)+abs(b-j)+abs(c-k),ansa=i,ansb=j,ansc=k;
    
                }
            }
        }
    }
    
}
/*
1
6 7
0 0 0 0 0 0
0 1 0 3 0 1
2 9 1 2 1 2
8 7 1 3 4 3
1 0 2 2 7 7
0 1 0 0 1 0
0 0 0 0 0 0
*/