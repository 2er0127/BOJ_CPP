// 연결리스트(forward_list 사용)에서 remove_if() 함수를 이용한 조건부 원소 삭제

#include <iostream>
#include <cstring>
#include <forward_list>

using namespace std;

struct citizen {
    string name;
    int age;
};

ostream &operator<<(ostream &os, const citizen &c) {
    return (os<<"["<<c.name<<", "<<c.age<<"]");
}

int main() {
    forward_list<citizen> citizens={
        {"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
    };
    
    auto citizens_copy=citizens; // 깊은 복사
    
    cout<<"전체 시민들: ";
    for(const auto &c : citizens)
        cout<<c<<" ";
    cout<<endl;
    
    // 투표권이 없는 시민은 리스트에서 제외
    citizens.remove_if([](const citizen &c) {
        // 나이가 19세 미만이면 리스트에서 삭제
        return (c.age<19); // 조건이 간단하기 때문에 람다 표현식 사용
    });
    
    cout<<"투표권이 있는 시민들 : ";
    for(const auto &c : citizens)
        cout<<c<<" ";
    cout<<endl;
    
    citizens_copy.remove_if([](const citizen &c) {
        return (c.age!=18);
    });
    
    cout<<"내년에 투표권이 생기는 시민들 : ";
    for(const auto &c : citizens_copy)
        cout<<c<<" ";
    cout<<endl;
}

