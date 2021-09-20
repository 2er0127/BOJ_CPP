#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct median { // 현재까지 받은 데이터를 저장할 컨테이너 정의. 두 개의 힙 사용(최대 힙, 최소 힙.).
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    void insert(int data) { // 새로 들어온 데이터를 저장하는 insert() 함수
        if(maxHeap.size()==0) {
            maxHeap.push(data);
            return;
        }
        
        if(maxHeap.size()==minHeap.size()) {
            if(data<=get())
                maxHeap.push(data);
            else
                minHeap.push(data);
            
            return;
        }
        
        if(maxHeap.size()<minHeap.size()) {
            if(data>get()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(data);
            }
            else
                maxHeap.push(data);
            
            return;
        }
        
        if(data<get()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(data);
        }
        else
            minHeap.push(data);
    }
}
