#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[200005];
string str;
vector<int> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d",&n);
        cin>>str;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(str[i]==str[i-1]) 
				cnt++;
            else
            {
                v.push_back(cnt); //将所有连续相同字符的子串长度存起来 例如如果是RRRLLRRR 则存取结果为 3 2 3 
                cnt=1; 
            }   
        }
        v.push_back(cnt);
        if(v.size()>1&&str[0]==str[n-1]) //如果发现最后一个字符与第一个字符相同，由于是循环，因此将他们合并 
        {
            v[v.size()-1]=v[0]+v.back(); //合并后的结果为 0 2 6 
            v[0]=0;
        }
        
        if(v.size()==1) //如果只是RRRR...或者LLLL...类型 ，完全相同的一段，则直接输出 
            printf("%d\n",1+(v[0]-1)/3);
        else //反之就是多段混合在一起的，这时利用vector中存取的各段长度，分别除3相加即可 
        {
            int ans=0;
            for(int i=0;i<v.size();i++) 
				ans+=v[i]/3;
            printf("%d\n",ans);
        }
    }
    return 0;
}
