#include <iostream>

using namespace std;

int main(void) {
    int a, b, v;
    cin>>a>>b>>v;
    
    int count=0;
    
    count=(v-b-1)/(a-b) + 1;
    
    cout<<count<<endl;
    
    return 0;
}
