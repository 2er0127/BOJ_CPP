#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

//선형 검색 함수
bool linear_search(int N, vector<int>& S) {
    for(auto i:S) {
        if(i==N)
            return true; //원소를 찾음
    }
    
    return false;
}

//이진 검색 함수
bool binary_search(int N, vector<int>& S) {
    auto first=S.begin();
    auto last=S.end();
    
    while(true) {
        //현재 검색 범위의 중간 원소를 mid_element에 저장
        auto range_length=distance(first, last);
        auto mid_element_index=first+floor(range_length/2);
        auto mid_element=*(first+mid_element_index);
        
        //mid_element와 N값을 비교
        if(mid_element==N)
            return true;
        
    }
}
