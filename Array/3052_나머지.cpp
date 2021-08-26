#include <iostream>

using namespace std;

int main() {
    int n[10]={0, };
    int count=0;
    
    for(int i=0; i<10; i++) {
        cin>>n[i];
        n[i]%=42;
    }
    
    for(int i=0; i<10; i++) {
        int no=0;
        for(int j=i+1; j<10; j++) {
            if(n[i]==n[j])
                no++;
        }
        if(no==0)
            count++;
    }
    cout<<count<<endl;
}
