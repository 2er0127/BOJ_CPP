#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int num[10001]={0}; //0으로 초기화 필수
    
    cin>>n;
    for(int i=0; i<n; i++) {
        int count;
        cin>>count;
        num[count]+=1;
    }
    
    for(int i=1; i<10001; i++) {
        for(int j=0; j<num[i]; j++) {
            cout<<i<<"\n";
        }
    }
}
