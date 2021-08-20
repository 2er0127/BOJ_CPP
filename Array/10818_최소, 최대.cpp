#include <iostream>

using namespace std;

int main() {
    int num;
    cin>>num;
    int arr[num];
    
    int min=1000000;
    int max=-1000000;
    
    for(int i=0; i<num; i++) {
        cin>>arr[i];
        if(max<arr[i])
            max=arr[i];
        if(min>arr[i])
            min=arr[i];
    }
    
    cout<<min<<" "<<max<<endl;
}
