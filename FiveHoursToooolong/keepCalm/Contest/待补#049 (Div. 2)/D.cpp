#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[305];
int b[305];
int main ()
{
    ios_base::sync_with_stdio(false); 
    int i,j,n,k;
    queue<pair<int,int> > q;
    cin >> n;
    for(i=1;i<=n;i++)
        cin >> a[i];
    for(i=1;i<=n;i++)
        cin >> b[i];
    for(i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
        {
            for(j=i+1;j<=n;j++)
            {
                if(a[i]==b[j])
                {
                    k = j;
                    break;
                }
            }
            for(j=k;j>i;j--)
            {
                q.push(make_pair(j-1,j));
                swap(b[j-1],b[j]);
            }
        }
    }
    cout << q.size() << endl;
    while(q.empty()!=1)
    {
        cout << q.front().first << " "<< q.front().second << endl;
        q.pop(); 
    }
    return 0;
}