#include<bits/stdc++.h>
using namespace std;
double sx, sy , gx , gy;
int main()
{
    cin >> sx >> sy >> gx >> gy;
    cout << std::fixed << std::setprecision(20) <<  (-1.0 * sy * (gx - sx) - sx * (gy + sy) ) / (-1.0 * (gy + sy)) << endl;
    return 0;
}