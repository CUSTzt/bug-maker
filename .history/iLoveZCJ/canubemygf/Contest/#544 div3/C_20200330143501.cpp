#include <bits/stdc++.h>
using namespace std;
int main()
{
   // multiset<long> res;
    vector<long> v;
    int n;
    cin>>n;
    long data;
    while(n--)
    {
        cin>>data;
        v.push_back(data);
    }
    sort(v.begin(),v.end());
    int j=0;
    int res=0;
    for(int i=0;i<v.size();i++)
    {
        while(j<v.size()&&(v[j]-v[i])<=5)
        {
            ++j;
            res=max(res,j-i);
        }
    }
    cout<<res;
 
}