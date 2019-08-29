 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-24 12:47:03
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
//A
//#include <bits/stdc++.h>
/*#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <stdio.h> 
using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int dp[1100][1100];
int main()
{
	string s1,s2;
	while(cin>>s1>>s2){
		memset(dp,0,sizeof(dp));
		int len1 = s1.length();
		int len2 = s2.length();
		for(int i = 0;i < len1;i++)
		{
			for(int j = 0; j <  len2;j++)
			{
				if(s1[i] == s2[j]){
					dp[i+1][j+1]=dp[i][j]+1;
				}
				else {
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
				}
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
}*/
//E
/*
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <stdio.h>
//others
//看组成了多少个环 总数就是n-环的数量
using namespace std;
int T,n;
int a[100086],b[100086];
int ans;
int vis[100086];
int x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans = 0;
        int same = 0;
        int loop = 0;
        memset(vis,0,sizeof(vis));
        cin>>n;
        for(int i = 0;i < n;i++)
        {
            cin>>x;
            a[x]=i;
        }
        for(int j = 0;j < n;j++)
        {
            cin>>x;
            b[j]=a[x];
        }
        for(int i = 0;i < n;i++)
        {

            if(b[i]!=i && !vis[i]){
                vis[i]=1;
                int k = b[i];
                while(!vis[k]){
                    vis[k] = 1;
                    k = b[k];
                }
                loop++;
            }
        }
        cout<<n-loop<<endl;
    }
}
*/
//C题
//wa
/*
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<string> v1,v2;
int dp[110][110];
std::vector<string> ans;
main()
{
	string s;
	while(cin>>s&&s!="#")
	{
		v1.push_back(s);
	}
	while(cin>>s&&s!="#")
	{
		v2.push_back(s);
	}
	//for(auto it = v1.begin();it != v1.end();it++)
	//	cout<<*it<<endl;
	int len1 = v1.size();
	int len2 = v2.size();
	int cnt = 0;
	//std::vector<string> ans;
	for(int i = 0;i < len1;i++)
		{
			for(int j = 0; j <  len2;j++)
			{
				if(v1[i] == v2[j]){
					dp[i+1][j+1]=dp[i][j]+1;
					//auto it = ans.find(v1[i]);
					//auto it = ans.find(ans.begin(),ans.end(),v1[i]);
					auto it = find(ans.begin(),ans.end(),v1[i]);
					//vector<string>::iterator it = find( ans.begin( ), ans.end( ), v1[i] );
					if(it == ans.end())
						ans.push_back(v1[i]),cnt++;
					//ans += v1[i]+" ";
				}
				else {
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
				}
			}
		}
		//cout<<dp[len1][len2]<<endl;
		//cout<<ans<<endl;
		for(auto it = ans.begin();it != ans.end()-1; it++)
			cout<<*it<<' ';
		cout<<ans[cnt-1]<<endl;
}
*/
//C题
//ac  others 
/*
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int vis[100][100];  //记录路径 
int dp[100][100];
string a[100];
string b[100];
string s;
void dfs(int len1,int len2)
{
	if(len1==0||len2==0) 
	  return;   //递归结束
	if(vis[len1][len2]==0)
	{
		dfs(len1-1,len2-1);
		cout<<a[len1-1]<<" ";
	 }
	else if(vis[len1][len2]==1)
	    dfs(len1,len2-1);
	else if(vis[len1][len2]==-1)
	    dfs(len1-1,len2);
}
int main()
{
	while(cin>>a[1])
	{   
	   
	    memset(vis,0,sizeof(vis));
	    memset(dp,0,sizeof(dp));
		int len1=2;
		int len2=1;
		while(cin>>s)
		{
			if(s=="#")  break;
			a[len1++]=s;
		}
		while(cin>>s)
		{
			if(s=="#")  break;
			b[len2++]=s;
		}
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				if(a[i-1]==b[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
					vis[i][j]=0;       //从左上来的 
				}
				else if(dp[i][j-1]>dp[i-1][j])
				{
					dp[i][j]=dp[i][j-1];
					vis[i][j]=1;    //从上面来的 
				}
				else
				{
					dp[i][j]=dp[i-1][j];
					vis[i][j]=-1;  //从左边来的 
				 } 
			}
		}
		dfs(len1,len2);   //输出 
		cout<<endl;
	}
	return 0;
}*/
//B题 难点：将最长公共子序列的所有情况输出
/*
首先我们预处理出alice串1~i的子串中，字符j+'a'最后一次出现的位置，存入pos1[i][j]。对bob串也做同样的处理。然后我们进行递归。len1表示alice子串长度，len2表示bob子串长度，len表示公共串的子串长度。
枚举26个字母，找到他们在子串中最后出现的位置，如果我们发现dp[p1][p2] = len，那么说明这是一种可行的方案。并且这表示，这个字母会出现在这个方案的len位置。
于是我们继续递归，去找(len1-1，len2-1,len-1)。直到len小于0了，说明现在当前跑出来的这个串跑完了，他是一个完整的方案，insert进set。如果在len到0之前，len1或者len2就已经小于0了，
说明这个方案最后不可行了，也就不会insert，而会回溯。整个过程相当于是一个dfs。
 */

//#include <bits/stdc++.h>
/*#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <map>
#include <set>

#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;


char alice[100], bob[100], tmp[100];
int dp[100][100], pos1[100][100], pos2[100][100];
set<string> ans;
int lena, lenb;

void solve(int len1, int len2, int len)
{
    if(len <= 0){
        string str;
        str = tmp + 1;
        //memset(tmp, 0, sizeof(tmp));
        //cout<<str<<endl;
        ans.insert(str);
        return;
    }
    if(len1 > 0 && len2 > 0){
        for(int i = 0; i < 26; i++){
            int p1 = pos1[len1][i];
            int p2 = pos2[len2][i];
            if(dp[p1][p2] == len){
                tmp[len] = i + 'a';
                solve(p1 - 1, p2 - 1, len - 1);
            }
        }
    }
}

int main()
{
    while(scanf("%s%s", alice + 1, bob + 1) != EOF){
        lena = strlen(alice + 1);
        lenb = strlen(bob + 1);
        //ans.clear();
        for(int i = 0; i <= lena; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= lenb; j++){
            dp[0][j] = 0;
        }
        //int tmpi = -1, tmpj = -1;
        for(int i = 1; i <= lena; i++){             //LCS
            for(int j = 1; j <= lenb; j++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if(alice[i] == bob[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        memset(pos1, -1, sizeof(pos1));
        memset(pos2, -1, sizeof(pos2));
        for(int i = 1; i <= lena; i++){
            for(int j = 0; j < 26; j++){
                if(alice[i] == j +'a'){
                    pos1[i][j] = i;
                }
                else{
                    pos1[i][j] = pos1[i - 1][j];
                }
            }
        }
        for(int i = 1; i <= lenb; i++){
            for(int j = 0; j < 26; j++){
                if(bob[i] == j + 'a'){
                    pos2[i][j] = i;
                }
                else{
                    pos2[i][j] = pos2[i - 1][j];
                }
            }
        }
        //printf("%d\n", dp[lena][lenb]);
        //memset(tmp, 0, sizeof(tmp));
        solve(lena, lenb, dp[lena][lenb]);
        set<string>::iterator iter;
        for(iter = ans.begin(); iter != ans.end(); iter++){
            cout<<*iter<<endl;
        }
    }
    return 0;
}
*/
/**
# include <iostream>
# include <cstdio>
# include <cstring>
# include <set>
# include <algorithm>
using namespace std;
char a[83], b[83], s[83];
int dp[83][83], l[83][83], r[83][83], max_len, alen, blen;
set<string>se;
void dfs(int x, int y, int icount)
{
    if(icount <= 0)
    {
        se.insert(&s[1]);
        return;
    }
    if(x>0 && y>0)
    for(int i=0; i<=25; ++i)
    {
        int p1 = l[x][i];
        int p2 = r[y][i];
        if(dp[p1][p2] == icount)
        {
            s[icount] = i+'a';
            dfs(p1-1, p2-1, icount-1);
        }
    }
}
 
void solve(int al, int bl)
{
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for(int i=1; i<=al; ++i)
        for(int j=0; j<=25; ++j)
        {
            if(a[i]==j+'a')
                l[i][j] = i;
            else
                l[i][j] = l[i-1][j];
        }
    for(int i=1; i<=bl; ++i)
        for(int j=0; j<=25; ++j)
        {
            if(b[i]==j+'a')
                r[i][j] = i;
            else
                r[i][j] = r[i-1][j];
        }
}
int main()
{
    while(~scanf("%s%s",a+1,b+1))
    {
        memset(s, 0, sizeof(s));
        memset(r, 0, sizeof(r));
        memset(dp, 0, sizeof(dp));
        alen = strlen(a+1);
        blen = strlen(b+1);
        for(int i=1; i<=alen; ++i)
            for(int j=1; j<=blen; ++j)
            {
                if(a[i]==b[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        max_len = dp[alen][blen];
        solve(alen, blen);
        dfs(alen, blen, max_len);
        set<string>::iterator it;
        for(it = se.begin(); it!=se.end(); it++)
            printf("%s\n",(*it).c_str());
    }
    return 0;

 */