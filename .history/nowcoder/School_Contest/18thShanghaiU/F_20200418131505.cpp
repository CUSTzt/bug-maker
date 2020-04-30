// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

// Routines for performing computations on dates.  In these routines,
// months are exprsesed as integers from 1 to 12, days are expressed
// as integers from 1 to 31, and years are expressed as 4-digit
// integers.

string dayOfWeek[] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};

// converts Gregorian date to integer (Julian day number)

int DateToInt(int m, int d, int y) {
    return 1461 * (y + 4800 + (m - 14) / 12) / 4 +
           367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
           3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 + d - 32075;
}

// converts integer (Julian day number) to Gregorian date: month/day/year

void IntToDate(int jd, int &m, int &d, int &y) {
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

// converts integer (Julian day number) to day of week

string IntToDay(int jd) { return dayOfWeek[jd % 7]; }

void solve(){
    int year , month , day;
    cin >> year >> month >> day ;
    int DD = DateToInt(month, day , year);
    //2000 05 14 母
    // int biaozhun  = DateToInt(5,14,2000);
    int YUANDAN = DateToInt(1,1,year);
    int a = DD
}
int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }


    return 0;
}