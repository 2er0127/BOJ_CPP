#include <iostream>
using namespace std;

int main(void){
    int a, b;
    int n1=0, n2=0, n3=0;
    
    cin>>a>>b;
    
    n1=b%10;
    n2=(b%100)/10;
    n3=b/100;
    
    cout<<a*n1<<endl;
    cout<<a*n2<<endl;
    cout<<a*n3<<endl;
    cout<<a*b<<endl;
    
}
