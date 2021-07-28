#include <iostream>

using namespace std;

void swapA(int&, int&);
void swapB(int*, int*);
void swapC(int, int);

int main(void) {
    int num1=100;
    int num2=200;
    
    cout<<"최초 상태"<<endl;
    cout<<"num1 = "<<num1<<", num2 = "<<num2<<"\n\n";
    
    cout<<"1.참조를 이용한 값의 교환\n";
    swapA(num1, num2);
    cout<<"참조 교환 이후 상태\n";
    cout<<"num1 = "<<num1<<", num2 = "<<num2<<"\n\n";
    
    cout<<"2.포인터를 이용한 값의 교환\n";
    swapB(&num1, &num2);
    cout<<"포인터 교환 이후 상태\n";
    cout<<"num1 = "<<num1<<", num2 = "<<num2<<"\n\n";
    
    cout<<"3.값을 이용한 값의 교환\n";
    swapC(num1, num2);
    cout<<"값 교환 이후 상태\n";
    cout<<"num1 = "<<num1<<", num2 = "<<num2<<endl; //교환 실패
    
    return 0;
}

//참조로 전달하는 방식
void swapA(int& a, int& b) {
    int temp;
    
    temp=a;
    a=b;
    b=temp;
}

//포인터로 전달하는 방식
void swapB(int* a, int* b) {
    int temp;
    
    temp=*a;
    *a=*b;
    *b=temp;
}

//값으로 전달하는 방식
void swapC(int a, int b) {
    int temp;
    
    temp=a;
    a=b;
    b=temp;
}

