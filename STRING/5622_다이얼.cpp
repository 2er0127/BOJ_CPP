#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    int arr[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
    int sum=0;
    string s;
    
    cin>>s;
    
    for(int i=0; i<s.length(); ++i) {
        int index=s[i]-'A';
        sum+=arr[index];
    }
    
    cout<<sum<<"\n";
    
    return 0;
}

