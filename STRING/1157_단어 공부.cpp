#include <iostream>
#include <cstring>

using namespace std;

//대문자 65~90 소문자 97~122
int main(void) {
    string str;
    getline(cin, str);

    int str2[26]={0, };
    for(int index=0; index<str.size(); index++) { //알파벳 횟수 배열에 저장
        if(str[index]>=97)
            str2[str[index]-'a']++;
        else
            str2[str[index]-'A']++;
    }
    
    int count=str2[0];
    int num=0;
    char word;
    for(int i=0; i<26; i++) { //가장 많이 나온 알파벳
        if(count<str2[i])
            count=str2[i];
    }
    for(int i=0; i<26; i++) { //가장 많이 나온 알파벳이 여러 개인지 검사하고 num++
        if(count==str2[i]) {
            word=i;
            num++;
        }
    }
    
    if(num>1) //가장 많이 나온 알파벳이 두 개 이상이면 ?
        cout<<"?"<<endl;
    else
        cout<<char(word+65)<<endl;
             
    return 0;
}
