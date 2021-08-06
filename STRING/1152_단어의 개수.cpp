#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    string str;
    
    getline(cin, str);
    
    int count=1;
    for(int i=0; i<str.length(); i++) {
        if(str[i]==' ')
            count++;
    }
    
    if(str[0]==' '|| str[0]=='\0')
        count--;
    
    if(str[str.length()-1]==' ')
        count--;
    
    cout<<count<<endl;
    
    return 0;
}
