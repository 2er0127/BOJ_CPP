#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string str;
    cin>>str;
    
    string cro[8]={"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    
    int count;
    for(int i=0; i<8; ++i) {
        while(true) {
            count=str.find(cro[i]); // find 함수로 찾기
            if(count==string::npos)
                break;
            
            str.replace(count, cro[i].length(), "a"); // a로 치환
        }
    }
    cout<<str.length()<<endl;
    
}
