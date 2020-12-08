#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[25];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        if(a[i]==0){
            if(i%2==0)return puts("YES"),0;
            break;
        }
    for(int i=n;i>=1;i--)
        if(a[i]==0){
            if((n-i+1)%2==0)return puts("YES"),0;
            break;
        }
    puts("NO");
    return 0;
}