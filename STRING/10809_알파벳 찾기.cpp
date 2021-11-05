#include <iostream>
#include <string>

using namespace std;
int main() {
    string s;
    string alp="abcdefghijklmnopqrstuvwxyz";
    cin>>s;
    
    for(int i=0; i<alp.length(); i++) {
        cout<<(int)s.find(alp[i])<<" "; //string의 멤버 함수 find
    }
}
