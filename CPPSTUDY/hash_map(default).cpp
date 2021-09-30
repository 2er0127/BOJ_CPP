#include <iostream>
#include <vector>

using namespace std;
using uint=unsigned int; //unsigned int 타입의 이름 대신 짧게 uint로 사용.

//hash_map class add.
class hash_map {
    vector<int> data;
    
//hash_map class의 생성자 추가. 해시 맵에서 사용할 데이터 크기를 인자로 받는다.
public:
    hash_map(size_t n) {
        data=vector<int>(n, -1); //벡터의 모든 원소를 -1로 초기화. 음수 데이터를 사용하지 않을 것이기 때문에 data 벡터의 값이 -1이라는 것은 해당 위치에 저장된 원소가 없음을 의마한다.
    }
    
    //삽입 함수 추가.
    void insert(uint value) {
        int n=data.size();
        data[value%n]=value;
        cout<<value<<"을(를) 삽입했습니다."<<endl; //특정 위치에 이미 다른 값이 존재하더라도 확인 없이 덮어쓴다. 해시 값이 중복된다면 나중에 삽입한 값만 저장된다.
    }
    
    //특정 원소가 맵에 있는지 확인한 룩업 함수 추가
    bool find(uint value) {
        int n=data.size();
        return (data[value%n]==value); //해시 값 위치에 저장된 값이 value와 같은지 검사
    }
    
    //삭제 함수 구현
    void erase(uint value) {
        int n=data.size();
        if(data[value%n]==value) {
            data[value%n]=-1;
            cout<<value<<"을(를) 삭제했습니다."<<endl;
        }
    }
};

int main() {
    hash_map map(7);
    
    //룩업 결과를 출력하는 람다 함수(lambda function)를 정의
    auto print=[&](int value) {
        if(map.find(value))
            cout<<"해시 맵에서 "<<value<<"을(를) 찾았습니다.";
        else
            cout<<"해시 맵에서 "<<value<<"을(를) 찾지 못했습니다.";
        cout<<endl;
    };
    
    map.insert(2);
    map.insert(25);
    map.insert(10);
    print(25);
    
    map.insert(100);
    print(100);
    print(2);
    
    map.erase(25);
}
