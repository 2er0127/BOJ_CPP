#include <iostream>
#include <vector>

using namespace std;

class hash_map {
    //두 개의 해시 테이블 사용, 각 테이블 크기를 멤버로 저장한다.
    vector<int> data1;
    vector<int> data2;
    int size;
    
    //두 개의 해시 함수 정의.
    int hash1(int key) const {
        return key%size;
    }
    int hash2(int key) const {
        return (key/size)%size;
    }
    
    //생성자 추가, 해시 테이블을 모두 -1로 초기화한다.(테이블이 비어 있음을 의미)
public:
    hash_map(int n) : size(n) {
        data1=vector<int>(size, -1);
        data2=vector<int>(size, -1);
    }
    
    //룩업 수행 함수.
    vector<int>::iterator lookup(int key) {
        auto hash_value1=hash1(key);
        if(data1[hash_value1]==key) {
            cout<<"1번 테이블에서 "<<key<<"을(를) 찾았습니다."<<endl;
            return data1.begin()+hash_value1;
        }
        
        auto hash_value2=hash2(key);
        if(data2[hash_value2]==key) {
            cout<<"2번 테이블에서 "<<key<<"을(를) 찾았습니다."<<endl;
            return data2.begin()+hash_value2;
        }
        
        return data2.end();
    } //룩업 함수는 양쪽 해시 테이블에서 키를 검색하고, 해당 위치를 나타내는 반복자를 반환한다. 이 반복자는 다음 삭제 함수에서 사용한다.
    //만약 원소를 찾지 못하면 data2의 테이블의 마지막을 가리키는 반복자가 반환된다. 룩업 함수는 O(1)의 시간 복잡도를 가지는 매우 빠른 함수다.
    
}
