// 각 리스트는 이미 정렬되어 있고 이들 원소로부터의 최솟값을 빠르게 선택하기 위해 힙을 사용.
// 힙, 벡터를 이용한 데이터 리스트 병합

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int data;
    int listPosition;
    int dataPosition;
};

vector<int> merge(const vector<vector<int>>& input) {
    auto comparator=[](const node& left, const node& right) {
        if(left.data==right.data)
            return left.listPosition>right.listPosition;
        return left.data>right.data;
    };
    
    vector<node> heap;
    for(int i=0; i<input.size(); i++) {
        heap.push_back({input[i][0], i ,0});
        push_heap(heap.begin(), heap.end(), comparator);
    }
    
    vector<int> result;
    while(!heap.empty()) {
        pop_heap(heap.begin(), heap.end(), comparator);
        auto min=heap.back();
        heap.pop_back();
        
        result.push_back(min.data);
        int nextIndex=min.dataPosition+1;
        if(nextIndex<input[min.listPosition].size()) {
            heap.push_back({input[min.listPosition][nextIndex], min.listPosition, nextIndex});
            push_heap(heap.begin(), heap.end(), comparator);
        }
    }
    
    return result;
}

int main() {
    vector<int> v1={1, 3, 8, 15, 105};
    vector<int> v2={2, 3, 10, 11, 16, 20, 25};
    vector<int> v3={-2, 100, 1000};
    vector<int> v4={-1, 0, 14, 18};
    
    auto result=merge({v1, v2, v3, v4});
    
    for(auto i:result)
        cout<<i<<' ';
    cout<<endl;
    
    return 0;
}
