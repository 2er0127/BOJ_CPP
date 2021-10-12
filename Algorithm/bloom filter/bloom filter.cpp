#include <iostream>
#include <vector>

using namespace std;

//블룸 필터 구현 클래스
class bloom_filter {
    vector<bool> data;
    int nBits;
    
    //해시 함수 추가
    //인자 num은 내부에서 어떤 해시 함수를 사용할지 결정하는 역할
    int hash(int num, int key) {
        switch(num) {
            case 0: return key%nBits;
            case 1: return (key/7)%nBits;
            case 2: return (key/11)%nBits;
        }
        
        return 0;
    }
    
//블룸 필터 생성자 추가
public:
    bloom_filter(int n):nBits(n) {
        data=vector<bool>(nBits, false);
    }
    
    //룩업 함수 추가
    void lookup(int key) {
        //필요한 모든 비트가 1로 설정되어 있는지 검사
        //가변 개수의 해시 함수를 사용한다면, 각각의 해시 함수와 연관된 비트가 모두 1로 설정되어 있는지 반복문을 통해 확인
        //특정 키를 '있을 수 있음'으로 출력하는 이유는 거짓과 긍정이 발생할 수 있기 때문
        //result 값이 0인 경우에는 입력 키가 없음이 확실하기 때문에 '절대 없음' 출력
        bool result=data[hash(0, key)]&data[hash(1, key)]&data[hash(2, key)];
        
        if(result) {
            cout<<key<<": 있을 수 있음"<<endl;
        }
        else {
            cout<<key<<": 절대 없음"<<endl;
        }
    }
    
    //삽입 함수
    void insert(int key) {
        data[hash(0, key)]=true;
        data[hash(1, key)]=true;
        data[hash(2, key)]=true;
        cout<<key<<"을(를) 삽입 : ";
        
        for(auto a:data)
            cout<<a<<" ";
        cout<<endl;
    }
};

int main() {
    bloom_filter bf(7);
    bf.insert(100);
    bf.insert(54);
    bf.insert(82);
    
    bf.lookup(5);
    bf.lookup(50);
    bf.lookup(20);
    bf.lookup(54);
}
