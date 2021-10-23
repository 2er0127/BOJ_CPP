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
    
    
}
