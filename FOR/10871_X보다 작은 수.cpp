#include <iostream>

using namespace std;

int main(void){
    int n, x;
    int number;
    int result=0;
    
    cin>>n>>x;
    
    for(int i=0; i<n; i++){
        cin>>number;
        if(number<x){
            result=number;
            cout<<result<<" ";
        }
    }
    
}
