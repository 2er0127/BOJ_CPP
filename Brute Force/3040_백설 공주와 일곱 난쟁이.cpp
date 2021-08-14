#include <iostream>

using namespace std;

int main() {
    int num[9]={0, };
    int sum=0;
    
    for(int index=0; index<9; index++) {
        cin>>num[index];
        sum+=num[index];
    }
    
    for(int i=0; i<8; i++) {
        bool answer=false;
        for(int j=i+1; j<9; j++) {
            if(sum-(num[i]+num[j])==100) {
                for(int k=0; k<9; k++) {
                    if(k!=i && k!=j) {
                        cout<<num[k]<<"\n";
                    }
                }
                answer=true;
                break;
            }
        }
        if(answer)
            break;
    }
}
