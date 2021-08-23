#include <iostream>

using namespace std;

int main() {
    int a[100];
    int max=0;
    int n=0;
    
    for(int i=1; i<10; i++) {
        cin>>a[i];
        if(max<a[i]) {
            max=a[i];
            n=i;
        }
    }
    cout<<max<<"\n"<<n;
}
