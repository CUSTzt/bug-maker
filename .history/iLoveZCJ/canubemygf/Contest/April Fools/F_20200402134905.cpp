// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
char s[200][5]={"H","HE","LI","BE","B","C","N","O","F","NE","NA","MG","AL","SI","P","S","CL","AR","K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN","GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR","NB","MO","TC","RU","RH","PD","AG","CD","IN","SN","SB","TE","I","XE","CS","BA","LA","CE","PR","ND","PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU","HF","TA","W","RE","OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN","FR","RA","AC","TH","PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR","RF","DB","SG","BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG"};
char t[15];
int f[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%s",t+1);
    f[0] = 1;
    int len = strnlen(t+1);
    for(int i =  1; i <= len; i++){
        for(int j = 0; j < 118; j++){
            if(strlen(s[j] )==1 && s[j][0] == t[i]){
                f[i] |= f[i-1];
            }
            if(strlen(s[j]) == 2&& s[j][0] == t[i-1] && s[j][1] == t[i]){
                f[i] |= f[i-2];
            }
        }
    }
    puts("YES":)
    return 0;
}