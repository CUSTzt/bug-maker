/*Lucky_Glass*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
struct String
{
    string s,ans;
    bool finish;
    String() {finish=false;s=ans="\0";}
}S[1005];
int main()
{
    int ls=0,mlen=0;
    while(cin>>S[ls].s)
        mlen=max(mlen,(int)S[ls].s.length()),ls++;
    for(int i=1;i<=mlen;i++)
    {
        bool G=true;
        map<string,int> F;
        for(int j=0;j<ls;j++)
            if(!S[j].finish)
                G=false,F[S[j].s.substr(0,i)]++;
        for(int j=0;j<ls;j++)
            if(!S[j].finish && F[S[j].s.substr(0,i)]==1)
            {
                S[j].ans=S[j].s.substr(0,i);
                S[j].finish=true;
            }
        if(G) break;
    }
    for(int i=0;i<ls;i++)
        cout<<S[i].s<<" "<<S[i].ans<<endl;
    return 0;
}