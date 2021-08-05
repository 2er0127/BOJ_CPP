/*
 다양한 타입의 데이터 여러 개를 인자로 받아 공통 타입으로 변환하는 함수
 이 함수가 반환하는 컨테이너는 모든 인자를 공통 타입으로 변환하여 저장하며, 전체 원소를 빠르게 순회할 수 있어야 한다.
 */
#include <iostream>
#include <array>
#include <type_traits>

using namespace std;

//컨테이너를 생성하는 build_array() 함수
//빠른 원소 순회를 보장하는 std::array를 반환. 임의 개수의 매개변수를 허용하기 위해 가변 템플릿을 사용.
//벡터도 사용할 수 있지만 함수의 인자 개수로부터 원소 개수를 유추할 수 있으므로 std::array를 사용
template<typename ... Args>
//std::array에 저장할 원소의 타입을 결정하기 위해 std::common_type 템플릿을 사용. 함수 인자에 의존적이기 때문에 함수 반환형을 후행 리턴 타입으로 지정
//원소 개수를 알아내는 코드와 commonType을 이용하여 배열 생성
auto build_array(Args&&... args)->array<typename common_type<Args...>::type, sizeof... (args)> {
    using commonType=typename common_type<Args...>::type;
    return {forward<commonType>((Args&&)args)...};
    
}

int main(void) {
    auto data=build_array(1, 0u, 'a', 3.2f, false);
    //auto data2=build_array(1, "seona", 2.0);
    //하나의 공통 타입으로 변환할 수 없기 때문에 에러가 발생
    
    for(auto i: data)
        cout<<i<<" ";
    cout<<endl;
    
    return 0;
}

