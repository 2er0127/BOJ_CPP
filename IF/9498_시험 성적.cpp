#include <iostream>

using namespace std;

int main(void){
    int jumsu;
    
    cin>>jumsu;
    
    if(jumsu>=90){
        cout<<"A"<<endl;
    }
    else if(jumsu>=80){
        cout<<"B"<<endl;
    }
    else if(jumsu>=70){
        cout<<"C"<<endl;
    }
    else if(jumsu>=60){
        cout<<"D"<<endl;
    }
    else{
        cout<<"F"<<endl;
    }
}
