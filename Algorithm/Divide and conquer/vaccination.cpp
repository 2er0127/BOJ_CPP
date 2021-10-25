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

//1부터 max 사이의 ID를 갖는 임의의 학생 정보를 생성.
auto generate_random_Student(int max) {
    random_device rd;
    mt19937 rand(rd());
    
    //학생 ID의 범위는 [1, max]로 지정
    uniform_int_distribution<mt19937::result_type> uniform_dist(1, max);
    
    //임의의 학생 정보 생성
    auto random_name=make_pair(uniform_dist(rand), uniform_dist(rand));
    bool is_vaccinated=uniform_dist(rand)%2?true:false;
    
    return Student(random_name, is_vaccinated);
}
