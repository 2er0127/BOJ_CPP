#include <iostream>

using namespace std;

int fibo(int);

int main() {
    int n;
    cin>>n;
    
    cout<<fibo(n)<<endl;
}

int fibo(int num) {
    if(num==0)
        return 0;
    if(num==1)
        return 1;
    return fibo(num-1)+fibo(num-2);
}
