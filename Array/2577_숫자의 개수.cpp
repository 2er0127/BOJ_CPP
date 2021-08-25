#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    
    int result=0;
    int arr[10000]={0, };
    
    result=a*b*c;
    
    while(result!=0) {
        int i=result%10;
        result/=10;
        arr[i]++;
    }
    
    for(int i=0; i<=9; i++) {
        cout<<arr[i]<<endl;
    }
}
