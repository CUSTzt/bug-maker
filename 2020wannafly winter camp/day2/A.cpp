#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
#define int long long 
const int maxn = 1e6+100;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
bool check(char c){
	if(c == 'a')return true;
	if(c == 'u')return true;
	if(c == 'o')return true;
	if(c == 'i')return true;
	if(c == 'e')return true;
	if(c == 'y')return true;

	return false;
}
double a[maxn];

void pre_work(){
	//a[1] = 1.0;
	a[1] = 1.0/2;
	for(int i = 2; i <= maxn; i++){
		a[i] = a[i-1] + 1.0/(i+1);
	}
}
int32_t main()
{
	pre_work();
	char s[maxn];
	scanf("%s", s+1);
	int len = strlen(s+1);
	//cout << "len === " << len << endl;
	int ans = 0;
	int fenmu = len*(len+1)/2;
	for(int i = 1; i <= len;i++){
		if(check(s[i])){
			//cout << i << endl;
			//ans = (ans + a[i] + 1.0 + a[len-i+1] + a[len -1]+a[len]);
			//cout << "1 " << endl;
			ans += min( i-1 , len - i)  a[max(i - 1,len-i) - min(i-1,len - i)] ;
		}
	}
	printf("%.10f\n",1.0*ans / fenmu );
}