#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

class Student {
private:
    pair<int, int> name; //학생 ID (이름, 성)
    bool vaccinated; //접종 여부
    
public:
    //생성자
    Student(pair<int, int> n, bool v) : name(n), vaccinated(v) {}
    
    //정보 검색
    auto get_name() {return name;}
    auto is_vaccinated() {return vaccinated;}
    
    //이름이 같으면 같은 사람으로 취급
    bool operator==(const Student& p) const {
        return this->name==p.name;
    }
    
    //이름을 이용하여 정렬하도록 설정
    bool operator< (const Student& p) const {
        return this->name < p.name;
    }
    bool operator> (const Student& p) const {
        return this->name > p.name;
    }
};
