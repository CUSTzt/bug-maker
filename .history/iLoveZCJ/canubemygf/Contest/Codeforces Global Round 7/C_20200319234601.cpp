#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define FI first
#define SE second
#define ULL unsigned long long
#define endl '\n'
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-8;
const int maxn=1<<17;
const int N=4e6+10,M=1e5+10,mod=998244353;
char a[N],b[N];
char s[N];
int p[N];
int ansid;
void manacher(int n){
    int re=0;
    int mx=0,id=0;
    int m=0;
    s[++m]='$';
    s[++m]='#';
    for(int i=1;i<=n;i++){
        s[++m]=a[i];
        s[++m]='#';
    }
    s[++m]='%';
    ansid=0;
    for(int i=3;i<m;i++){
        p[i]=i<mx?min(p[id*2-i],mx-i):1;
        while(s[i+p[i]]==s[i-p[i]])++p[i];
        if(i+p[i]>mx){
            mx=i+p[i];
            id=i;
        }
        if(i+p[i]-1>=n*2+1||i-p[i]+1<=3){
            if(p[i]>re)re=p[i],ansid=i;
        }
    }
    /*
    cout<<endl;
    for(int i=1;i<=m;i++)cout<<s[i];cout<<endl;
    for(int i=ansid-re+1;i<=ansid+re-1;i++)cout<<s[i];cout<<endl;
    //*/
    //cout<<' ';

    for(int i=ansid-re+1;i<=ansid+re-1;i++){
        if(s[i]<='z'&&s[i]>='a')printf("%c",s[i]);
    }//cout<<' ';
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        scanf("%s",b+1);
        int len=strlen(b+1);
        int ans=0;
        while(ans+1<=len/2&&b[ans+1]==b[len-ans])ans++;
        int cnt=0;
        for(int i=1;i<=ans;i++)printf("%c",b[i]);
        for(int i=ans+1;i<=len-ans;i++)a[++cnt]=b[i];
        manacher(cnt);
        for(int i=ans;i>=1;i--)printf("%c",b[i]);printf("\n");
    }
    return 0;
}