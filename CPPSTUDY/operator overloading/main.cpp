#include <iostream>
#include "time.hpp"

using namespace std;

/*
 클래스란? 추상화를 사용자 정의 데이터형으로 변환해주는 수단
 1. 클래스 선언
 2. 클래스 메서드 정의
 추상화란? 어떠한 객체를 사실적으로 표현하는 것이 아니라,
            공통된 특징을 간결한 방식으로 이해하기 쉽게 표현하는 것
 */

int main(void) {
    Time day1(1, 40);
    Time day2(2, 30);
    
    day1.show();
    day2.show();
    
    Time total;
    total=day1.operator+(day2);
    total.show();
    
    return 0;
}
