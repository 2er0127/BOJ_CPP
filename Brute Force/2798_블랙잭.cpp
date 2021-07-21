#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int n, m;
    int cardNum[100000];
    int result=0;
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        cin>>cardNum[i];
    }
    for(int i=0; i<n; i++){ //첫번째
        for(int j=i+1; j<n; j++){ //두번째
            for(int k=j+1; k<n; k++){ //세번째
                if(cardNum[i]+cardNum[j]+cardNum[k] <= m)
                    result=max(result, cardNum[i]+cardNum[j]+cardNum[k]);
            }
        }
    }
    cout<<result<<"\n";
    
}
