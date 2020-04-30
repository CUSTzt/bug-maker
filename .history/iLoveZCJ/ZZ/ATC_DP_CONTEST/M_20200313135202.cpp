#include<bits/stdc++.h>
using namespace std;
int num;
void move(int x, char a , char b , char c){ // a起始座，b辅助座，c终点座
    if(x == 1) printf("%c --> %c\n", a, c); // 盘子数量为1时候
    else{
        move(x-1, a , c , b);  //先将前x-1个盘借助c放到b上
        printf("%c --> %c\n", a, c); // 将最后一个盘子放到目标座
        move(x-1 , b , a , c);//将前x-1个盘借助a放到c上
    }
}
void Hanoi(int x){
    move(x , 'A', 'B', 'C');
}
int main()
{
    clock_t start,end;
    start=clock();
    cout << "请输入盘的数量："<<endl;
    cin >> num;
    Hanoi(num);
    end=clock();
    printf("%.5lfms\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
    return 0;
}