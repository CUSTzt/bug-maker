#include<bits/stdc++.h>
using namespace std;
int num;
void move(int x, char a , char b , char c){ // a��ʼ����b��������c�յ���
    if(x == 1) printf("%c --> %c\n", a, c); // ��������Ϊ1ʱ��
    else{
        move(x-1, a , c , b);  //�Ƚ�ǰx-1���̽���c�ŵ�b��
        printf("%c --> %c\n", a, c); // �����һ�����ӷŵ�Ŀ����
        move(x-1 , b , a , c);//��ǰx-1���̽���a�ŵ�c��
    }
}
void Hanoi(int x){
    move(x , 'A', 'B', 'C');
}
int main()
{
    clock_t start,end;
    start=clock();
    cout << "�������̵�������"<<endl;
    cin >> num;
    Hanoi(num);
    end=clock();
    printf("%.5lfms\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
    return 0;
}