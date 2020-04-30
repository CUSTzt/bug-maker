#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=1e6+10,ha=26,mod=1e9+7;
const double pi=acos(-1),eps=1e-8;
int n;
char a[N];
int s[N];
int b[N];

void solve(){
    scanf("%d%s",&n,a+1);
    int k=n,cnt=0;
    for(int i=1;i<=n;i++)b[i]=0;
    for(int i=1;i<n;i++){
        cnt++;
        if(a[i]=='>')b[i]=k,k-=cnt,cnt=0;
    }
    //for(int i=1;i<=n;i++)printf("%d ",b[i]);printf("\n");
    b[n]=k;

    //cout<<1<<endl;
    for(int i=n-1;i>=1;i--){
        if(b[i]==0)b[i]=b[i+1]-1;
    }
    for(int i=1;i<=n;i++)printf("%d ",b[i]);printf("\n");

   for(int i=1;i<=n;i++)b[i]=0;
    k=n,cnt=0;
    for(int i=n-1;i>=1;i--){
        cnt++;
        if(a[i]=='<')b[i+1]=k,k-=cnt,cnt=0;
    }
    b[1]=k;
    for(int i=2;i<=n;i++){
        if(b[i]==0)b[i]=b[i-1]-1;
    }
    for(int i=1;i<=n;i++)printf("%d ",b[i]);printf("\n");
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
	cin >> n >> m;
	//set<string >st;
	int fl = 0;
		deque<string >ans;
	for(int i = 0;i < n; i++){
		cin >> s[i];
		/*string t = s[i];
		reverse(t.begin(),t.end());*/
		//cout << "t ==" << t << endl << "s == " << s[i] << endl;
		//if(strcmp(t.c_str(),s[i].c_str())==0&& !fl){ans.push_back(t);fl = 1;}
		if( !fl && check(s[i])){ans.push_back(s[i]);fl = 1;}//cout << "kp\n";}
		else {
			a[i] = 1;
		}
		//if(a[i] == 1)st.insert(s[i]);
	}
	for(int i = 0; i < n; i++){
		if(a[i] == 2){
			ans.push_back(s[i]);
			break;
		}
	}
	//int cnt = 10;
	for(int i = 0; i < n; i++){
		string p = s[i];
		reverse(p.begin(),p.end());
		for(int j = i+1; j < n; j++){
			if(s[j] == p){
				ans.push_back(s[i]);
				ans.push_front(s[j]);
			}
		}
	}
	int size = ans.size()*m;
	cout << size << endl;
	while(!ans.empty()){
		cout << ans.front();
		ans.pop_front();
	}
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
