#include <string>
#include <vector>

using namespace std;

//두 개의 벡터를 병합하는 merge() 함수
template<typename T>
vector<T> merge(vector<T>& arr1, vector<T>& arr2) {
    vector<T> merged;
    
    auto iter1=arr1.begin();
    auto iter2=arr2.begin();
    
    while(iter1!=arr1.end()&&iter2!=arr2.end()) {
        if(*iter1<*iter2) {
            merged.emplace_back(*iter1);
            iter1++;
        }
        else {
            merged.emplace_back(*iter2);
            iter2++;
        }
    }
    
    if(iter1!=arr1.end()) {
        for(; iter1!=arr1.end(); iter1++)
            merged.emplace_back(*iter1);
    }
    else {
        for(; iter2!=arr2.end(); iter2++)
            merged.emplace_back(*iter2);
    }
    
    return merged;
}
