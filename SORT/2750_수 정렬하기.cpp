#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int num[1000];
    
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>num[i];
    }
    sort(num, num+n); //오름차순으로 다시 정렬 후 출력
    for(int i=0; i<n; i++) {
        cout<<num[i]<<"\n";
    }
    
}
