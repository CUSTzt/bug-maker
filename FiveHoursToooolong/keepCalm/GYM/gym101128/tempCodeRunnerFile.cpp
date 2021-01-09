#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    map<char , int>mp;
    getline(cin ,s);
    for(auto c:s){
        if(c>='A'&&c<='Z')c-=32;
        if(c>='a'&&c<='z')mp[c]++;
    }
    cout << mp.size() << endl;
}