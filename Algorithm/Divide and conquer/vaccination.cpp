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

bool needs_vaccination(Student P, vector<Student>& people) {
    auto first=people.begin();
    auto last=people.end();
    
    while(true) {
        auto range_length=distance(first, last);
        auto mid_element_index=floor(range_length/2);
        auto mid_element=*(first+mid_element_index);
        
        //목록에 해당 학생이 있고, 예방 접종을 받지 않은 학생에 대해 true를 반환
        if(mid_element==P&&mid_element.is_vaccinated()==false)
            return true;
        //목록에 해당 학생이 있는데 이미 예방 접종을 받은 학생에 대해 false를 반환
        else if(mid_element==P&&mid_element.is_vaccinated()==true)
            return false;
        else if(mid_element>P)
            advance(last, -mid_element_index);
        if(mid_element<P)
            advance(first, mid_element_index);
        
        //목록에 해당 학생이 없다면 true를 반환
        if(range_length==1)
            return true;
    }
}

void search_test(int size, Student P) {
    vector<Student> people;
    
    //임의의 학생 정보 목록 생성
    for(auto i=0; i<size; i++)
        people.push_back(generate_random_Student(size));
    
    sort(people.begin(), people.end());
    
    //이진 검색 실행 및 시간 측정
    auto begin=chrono::steady_clock::now();
    
    bool search_result=needs_vaccination(p, people);
    
    auto end=chrono::steady_clock::now();
    auto diff=chrono::duration_cast<chrono::microseconds>(end-begin);
    
    cout<<"이진 검색 소요 시간: "<<diff.count()<<"us"<<endl;
    
    if(search_result)
        cout<<"("<<p.get_name().first<<" "<<p.get_name().second<<")"<<"학생은 예방 접종이 필요합니다."<<endl;
    else
        cout<<"("<<p.get_name().first<<" "<<p.get_name().second<<")"<<"학생은 예방 접종이 필요하지 않습니다."<<endl;
}

int main() {
    //임의의 학생 정보 생성
    auto p.generate_random_Student(1000);
    
    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);
    
    return 0;
}
