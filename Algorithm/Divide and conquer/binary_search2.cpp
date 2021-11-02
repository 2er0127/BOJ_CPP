#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

bool linear_search(int N, std::vector<int>& S)
{
    for (auto i : S) {
        if (i == N)
            return true; //원소를 찾음!
    }
    return false;
}

bool binary_search(int N, vector<int>& S) {
    auto first = S.begin();
    auto last = S.end();

    while (true) {
        //현재 검색 범위의 중간 원소를 mid_element에 저장
        auto range_length = distance(first, last);
        auto mid_element_index = floor(range_length/2);
        auto mid_element = *(first + mid_element_index);

        //mid_element와 N 값을 비교
        if (mid_element == N)
            return true;
        else if (mid_element>N)
            advance(last, -mid_element_index);
        else
            advance(first, mid_element_index);

        //현재 검색 범위에 하나의 원소만 남아 있다면 false를 반환
        if (range_length == 1)
            return false;
    }
}
