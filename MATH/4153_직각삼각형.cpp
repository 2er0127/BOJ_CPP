#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int h, x, a;
    while(true) {
        cin>>h>>x>>a;
        if(h*x*a==0)
            break;
        h=pow(h, 2);
        x=pow(x,2);
        a=pow(a,2);
        
        if(h+x==a||x+a==h||h+a==x) // 직각삼각형
            cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;
    }
}
