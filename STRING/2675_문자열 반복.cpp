#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int num;
    string str;
    
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>num>>str;
        
        for(int j=0; j<str.length(); j++) {
            for(int k=0; k<num; k++) {
                cout<<str[j];
            }
        }
        cout<<endl;
    }
}
