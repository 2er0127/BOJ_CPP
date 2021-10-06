#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//컨테이너에 들어 있는 모든 원소를 출력하는 print() 함수.
void print(const unordered_set<int>& container) {
    for(const auto& element:container)
        cout<<element<<" ";
    cout<<endl;
}

void print(const unordered_map<int, int>& container) {
    for(const auto& element:container)
        cout<<element.first<<": "<<element.second<<", ";
    cout<<endl;
}

//화면 출력 find() 함수.
void find(const unordered_set<int>& container, const int element) {
    if(container.find(element)==container.end())
        cout<<element<<" 검색: 실패"<<endl;
    else
        cout<<element<<" 검색: 성공"<<endl;
}

void find(const unordered_map<int, int>& container, const int element) {
    auto it=container.find(element);
    if(it==container.end())
        cout<<element<<" 검색: 실패"<<endl;
    else
        cout<<element<<" 검색: 성공, 값= "<<it->second<<endl;
}

