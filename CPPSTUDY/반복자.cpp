#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main() {
    vector<string> vec = {
        "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg", "Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel", "Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
    };
    
    auto it=vec.begin();
    cout<<"가장 최근 우승자 : "<<*it<<endl;
    
    it+=8;
    cout<<"8년 전 우승자 : "<<*it<<endl;
    
    advance(it, -3);
    cout<<"그후 3년 뒤 우승자 : "<<*it<<endl;
    
}
