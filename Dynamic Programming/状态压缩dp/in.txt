1 #include<bits/stdc++.h>
 2 using namespace std;
 3 int read()
 4 {
 5    int x=0,f=1;char ch=getchar();
 6    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
 7    while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
 8    return x*f;
 9 }
10 const int inf=0x3f3f3f3f;
11 map<int,int> mp;
12 int n,m,a[12][12],b[12][12],vis[12],w[12][12];
13 int dfs(int op,int hsh)
14 {
15     if (mp[hsh]) return mp[hsh];
16     if (vis[n]==m) return 0;
17     int ans=(op==0)?inf:-inf;
18     for (int i=1;i<=n;i++) 
19         if (vis[i]!=vis[i-1]&&vis[i]!=m) 
20         {
21             vis[i]++;
22            if (op==0) ans=min(ans,dfs(op^1,hsh^w[i][vis[i]])-b[i][vis[i]]);
23            else ans=max(ans,dfs(op^1,hsh^w[i][vis[i]])+a[i][vis[i]]);
24            vis[i]--;
25         }
26     return mp[hsh]=ans;
27 }
28 int main()
29 {
30     srand(time(NULL));
31     n=read();m=read();
32     for (int i=1;i<=n;i++)
33       for (int j=1;j<=m;j++) a[i][j]=read();
34    for (int i=1;i<=n;i++)
35      for (int j=1;j<=m;j++) b[i][j]=read(),w[i][j]=rand();
36    vis[1]=1;
37     printf("%d\n",a[1][1]+dfs(0,0));
38    return 0;
39 }