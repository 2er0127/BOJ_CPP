#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> list1={1, 2, 3, 4, 5};
    list1.push_back(6);
    list1.insert(next(list1.begin()), 0);
    list1.insert(list1.end(), 7);
    
    list1.pop_back();
    
    cout<<"삽입 & 삭제 후 리스트 : ";
    for(auto i : list1)
        cout<<i<<" ";
}