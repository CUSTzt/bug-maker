#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define int long long 
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
int a[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const ll NEED = 999999999+1;
bool isleap(int x){
    if(x % 400 == 0 || (x % 4 == 0 && x % 100 != 0) )return true;
    return false;
}
int DateToInt (int m, int d, int y){  
  return 
    1461 * (y + 4800 + (m - 14) / 12) / 4 +
    367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 
    3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 + 
    d - 32075;
}

// converts integer (Julian day number) to Gregorian date: month/day/year

void IntToDate (int jd, int &m, int &d, int &y){
  int x, n, i, j;

  x = jd + 68569;
  n = 4 * x / 146097;
  x -= (146097 * n + 3) / 4;
  i = (4000 * (x + 1)) / 1461001;
  x -= 1461 * i / 4 - 31;
  j = 80 * x / 2447;
  d = x - 2447 * j / 80;
  x = j / 11;
  m = j + 2 - 12 * x;
  y = 100 * (n - 49) + i + x;
}
int32_t main()
{
    CASET{
        int w, year , month , day;
        cin >> w >> year >> month >> day;
        int need = NEED - w;
        int needday ;
        int m = sqrt(2.0*need/11);
        for(int i = m-100;;i++){
            if(11ll*(1+i)*i/2 >= need){
                needday = i;
                break;
            }
        }
        int ansyear = year , ansmonth = month, ansday = day;
        int Y;
        int zcj = DateToInt(year , month , day);
        IntToDate(needday, year , month , day);
        cout << year < month << ' ' <<day << endl;       
        /*if(isleap(year))a[2]=29, Y=366;else a[2] = 28,Y=365;

        while(needday){
            if(isleap(year))a[2]=29, Y=366;else a[2] = 28,Y=365;
            if(needday >= Y){
                needday -= Y;
                ansyear ++;
                continue;
            }
            if(ansmonth < 13){
                if(needday > a[ansmonth] - ansday){
                    //ansmonth++;
                    needday-=(a[ansmonth++]);
                }else {
                    ansday+=needday;
                    needday = 0;
                }
            }else {
                ansyear++;
                ansmonth = 1;
            }
        }
        cout << ansyear << ' ' << ansmonth << ' ' << ansday << endl;*/
    }
}